#include <bits/stdc++.h>

using namespace std;

inline uint64_t mul(uint64_t x, uint64_t y, uint64_t mod) {
    uint64_t q = (uint64_t)((double)x * y / mod + 0.5);
    int64_t r = x * y - mod * q;
    if (r < 0) r += mod;
    return r;
}

inline uint64_t add(uint64_t x, uint64_t y, uint64_t mod) {
    return x < mod - y ? x + y : x - (mod - y);
}

inline uint64_t sub(uint64_t x, uint64_t y, uint64_t mod) {
    return x < y ? x + (mod - y) : x - y;
}

uint64_t qpow(uint64_t x, uint64_t n, uint64_t mod) {
    for (uint64_t y = 1; ; x = mul(x, x, mod)) {
        if (n & 1) y = mul(x, y, mod);
        if ((n /= 2) == 0) return y;
    }
}

uint64_t gcd(uint64_t x, uint64_t y) {
    for (; y; swap(x %= y, y));
    return x;
}

bool isPrime(uint64_t n){
	const uint64_t f = n - 1;
	int s = __builtin_ctzll(f);
    uint64_t m = f >> s;
	for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
        if (n % p == 0) return n == p;
		uint64_t x = qpow(p, m, n);
		if (x == 1) continue;
		for (int u = 0; x != f; x = mul(x, x, n)) {
			if (++u == s)
                return false;
		}
	}
	return true;
}

uint64_t rho(uint64_t n, uint64_t x, uint64_t c) {
    auto f = [n, c](uint64_t x) {
        x += c;
        return mul(x, x, n);
    };
    const int STEP = 128;
    for (int pow = 1; pow < STEP; pow *= 2) {
        uint64_t y = x, z = 1;
        for (int lam = 0; lam < pow; ++lam) {
            uint64_t u[STEP];
            for (int i = 0; i < STEP; ++i) {
                y = f(y);
                u[i] = z = mul(z, sub(x, y, n), n);
            }
            uint64_t g = gcd(n, z);
            if (g == 1) continue;
            if (g != n) return g;
            int lo = 0, hi = STEP - 1;
            for (; lo < hi; ) {
                int mid = lo + (hi - lo) / 2;
                g = gcd(n, u[mid]);
                if (g == 1) lo = mid + 1;
                else if (g == n) hi = mid;
                else return g;
            }
            return n;
        }
        x = y;
    }
    return n;
}

class Factorizer {
public:
    Factorizer() {
        const int B1 = 128;
        bitset<B1> sieve;
        for (int i = 3; i < B1; i += 2) {
            if (!sieve[i]) {
                smallPrimes.push_back(i);
                for (int j = i * i; j < B1; j += 2 * i)
                    sieve[i] = true;
            }
        }
    }

    vector<uint64_t> operator()(uint64_t n) {
        vector<uint64_t> res;
        for (int p : smallPrimes) {
            if (n % p == 0) {
                res.push_back(p);
                do n /= p; while (n % p == 0);
            }
        }
        for (; n > 1; ) {
            uint64_t d = findPrimeDivisor(n);
            res.push_back(d);
            do n /= d; while (n % d == 0);
        }
        return res;
    }

private:
    std::unordered_map<uint64_t, uint64_t> cache;
    vector<int> smallPrimes = {2};

    uint64_t findPrimeDivisor(uint64_t n) {
        uint64_t& d = cache[n];
        if (d) return d;
        if (isPrime(n)) return d = n;
        uint64_t s = (uint64_t)sqrt(n);
        s = (s + n / s) / 2;
        if (s * s == n) return d = findPrimeDivisor(s);
        for (uint64_t c = 1; ; ++c) {
            d = rho(n, 2, c);
            if (d != n) return d = findPrimeDivisor(d);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    int T;
    cin >> T;
    vector<bool> res(T);
    unordered_map<uint64_t, vector<pair<uint64_t, int>>> queries;
    for (int i = 0; i < T; ++i) {
        uint64_t n, k;
        cin >> n >> k;
        queries[k].emplace_back(n, i);
    }
    Factorizer factorizer;
    for (auto& query : queries) {
        vector<uint64_t> pd = factorizer(query.first);
        sort(pd.begin(), pd.end());
        switch (pd.size()) {
            case 0: break;
            case 1: {
                for (auto& v : query.second)
                    res[v.second] = (v.first % pd[0]) == 0;
                break;
            }
            case 2: {
                uint64_t p = pd[0], q = pd[1];
                uint64_t r = qpow(p, q - 2, q);
                for (auto& v : query.second) {
                    uint64_t n = v.first;
                    uint64_t a = mul(r, n, q);
                    if (n >= p * a) {
                        res[v.second] = true;
                    }
                }
                break;
            }
            default: {
                int p = (int)pd[0];
                vector<uint64_t> f(p, -1ull/2);
                f[0] = 0;
                pd.erase(pd.begin());
                for (uint64_t q : pd) {
                    int x = 0, r = (int)(q % p);
                    for (int k = 2 * p; k --> 0; ) {
                        int y = (int)add(x, r, p);
                        f[y] = min(f[y], f[x] + q);
                        x = y;
                    }
                }
                for (auto& v : query.second) {
                    uint64_t n = v.first;
                    res[v.second] = f[n % p] <= n;
                }
            }
        }
    }
    for (int i = 0; i < T; ++i) {
        puts(res[i] ? "YES" : "NO");
    }
    return 0;
}