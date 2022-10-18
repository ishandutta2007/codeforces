#include <bits/stdc++.h>

using namespace std;

#define int uint64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int mul(int a, int b, int half = 32);

int P[64][64];

int mul2(int a, int b) {
    if(a == 0 || b == 0) {
        return 1LL << (a + b);
    } else if(P[a][b]) {
        return P[a][b];
    } else {
        int n = 1;
        while(2 * n <= max(a, b)) {
            n *= 2;
        }
        if (a >= n && b >= n) {
            return P[a][b] = mul((3ULL << (n - 1)), mul2(a - n, b - n));
        } else if (a >= n) {
            return P[a][b] = mul2(a - n, b) << n;
        } else {
            return P[a][b] = mul2(a, b - n) << n;
        }
    }
}

// a * 2^k
int mul_with_pow(int a, int k) {
    int res = 0;
    while(a) {
        int t = __builtin_ctzll(a);
        res ^= mul2(t, k);
        a ^= 1ULL << t;
    }
    return res;
}

const int cache = 1024;
int small[cache][cache];

int mul(int a, int b, int half) {
    if(a <= 1 || b <= 1) {
        return a * b;
    }
    int mask = (1ULL << half) - 1;
    auto [a0, a1] = make_pair(a & mask, a >> half);
    auto [b0, b1] = make_pair(b & mask, b >> half);
    if(a < cache && b < cache && small[a][b]) {
        return small[a][b];
    }
    assert(max({a0, a1, b0, b1}) <= mask);
    int A = mul(a0, b0, half / 2);
    int C = mul(a1, b1, half / 2);
    int B = mul(a0 ^ a1, b0 ^ b1, half / 2) ^ A ^ C;
    
    B = mul_with_pow(B, half);
    C = mul_with_pow(C, half) ^ mul_with_pow(C, half - 1);
    
    int result = A ^ B ^ C;
    if(a < cache && b < cache) {
        small[a][b] = result;
    }
    return result;
}

int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

const int K = 7;
int factors[K] = {3, 5, 17, 257, 641, 65'537, 6'700'417};

int bpow(int x, int n, int m) {
	return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1;
}

int C[K];
unordered_map<int, int> rev_pow[K];


int longsum(int a, int b) {
	if(b && a >= -b) { // a + b > 2^64
		a += b + 1;
		return a == -1ULL ? 0 : a;
	} else {
		a += b;
		return a == -1ULL ? 0 : a;
	}
}

int longmul(int a, int b) {
	return b ? b % 2 ? longsum(a, longmul(a, b - 1)) : longmul(longsum(a, a), b / 2) : 0;
}

int longpow(int x, int n) {
	return n ? n % 2 ? longmul(x, longpow(x, n - 1)) : longpow(longmul(x, x), n / 2) : 1;
}

const int phi = 9'208'981'628'670'443'520LL;

int recover(int *rems) {
	int ans = rems[0];
	int mod = factors[0];
	for(int i = 1; i < K; i++) {
		int k = (rems[i] - ans % factors[i] + factors[i]) * bpow(mod % factors[i], factors[i] - 2, factors[i]) % factors[i];
		ans += k * mod;
		mod *= factors[i];
	}
	return ans;
}

int get_log(int x) {
	int base = -1ULL;
	int rems[K];
	for(int i = 0; i < K; i++) {
		int sqr = sqrt(factors[i]) + 1;
		int cur = bpow(x, base / factors[i]), step = bpow(base, base / factors[i]);
		for(int j = 0; j < sqr; j++) {
			if(rev_pow[i].count(cur)) {
				rems[i] = (rev_pow[i][cur] - j + factors[i]) % factors[i];
				break;
			}
			cur = mul(cur, step);
		}
	}
	return recover(rems);
}

void solve() {
	int a, b;
	cin >> a >> b;
	int A = get_log(a);
	int B = get_log(b);
	int base = -1ULL;
	assert(a == bpow(base, A));
	assert(b == bpow(base, B));
	// A * k = B (mod 2^64 - 1)
	int G = __gcd(A, base);
	if(B % G != 0) {
		cout << -1 << "\n";
	} else {
		A /= G; B /= G;
		cout << (longmul(B, longpow(A, phi - 1)) % (base / G)) << "\n";
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int base = -1ULL;
	for(int i = 0; i < K; i++) {
		int sqr = sqrt(factors[i]) + 1;
		int cur = 1, step = bpow(base, base / factors[i] * sqr);
		for(int j = 0; j < sqr; j++) {
			rev_pow[i][cur] = j * sqr;
			cur = mul(cur, step);
		}
	}
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}