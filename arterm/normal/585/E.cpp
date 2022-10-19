#include <bits/stdc++.h>


using namespace std;

#define long long long
#define div asdlkfjalsdkfas

const int mod = 1000000007;
const int M = 10000007;

int cnt[M];
int f[M], d[M];

long bin(long x, long a) {
    long y = 1;
    while (a) {
        if (a & 1)
            y = (y * x) % mod;
        x = (x * x) % mod;
        a >>= 1;
    }
    return y;
}

void read() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }
}

void calc() {
    for (int i = 1; i < M; ++i) {
        int sum = 0;
        for (int j = i; j < M; j += i) {
            sum += cnt[j];
        }
        f[i] = bin(2, sum) - 1;
    }

    for (int i = M - 1; i >= 1; --i) {
        d[i] = f[i];
        for (int j = i + i; j < M; j += i) {
            d[i] -= d[j];
            if (d[i] < 0)
                d[i] += mod;
        }
    }
}

bool used[M];
int div[M];

void sito() {
    for (int i = 2; i < M; ++i)
        if (!used[i]) {
            div[i] = i;
            if (1ll * i * i < M)
                for (int j = i * i; j < M; j += i) {
                    used[j] = true;
                    div[j] = i;
                }
        }
}

vector<int> getPrimes(int x) {
    vector<int> ans;
    while (x > 1) {
        int p = div[x];
        ans.push_back(p);
        while (x % p == 0)
            x /= p;
    }
    return ans;
}


void kill() {
    long ans = 0;
    for (int i = 1; i < M; ++i)
        if (cnt[i]) {
            auto primes = getPrimes(i);
            int n = primes.size();
            for (int mask = 0; mask < (1 << n); ++mask) {
                int prod = 1, sign = 1;
                for (int i = 0; i < n; ++i)
                    if ((mask >> i) & 1) {
                        prod *= primes[i];
                        sign *= -1;
                    }
                ans = (ans + 1ll * cnt[i] * sign * f[prod]) % mod;
            }
            ans = (ans - 1ll * cnt[i] * d[1]) % mod;
        }
    if (ans < 0)
        ans += mod;
    cout << ans << endl;
}

int main() {
    read();
    sito();
    calc();
    kill();
    return 0;
}