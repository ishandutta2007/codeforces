#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cout << "Case #" << testNum++ << ": ";
        //cerr << testNum << endl;
        solve(true);
        //cerr << testNum - 1 << endl;
    }
    cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
    cout.flush();
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

void precalc() {
}

//#define int li
//const int mod = 1000000007;

long long pw(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1ll) {
            res = res * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve(bool read) {
    int n, m, a, q;
    cin >> n >> m >> a >> q;

    int p = 0;
    long long cur = 1;
    do {
        cur = cur * a % q;
        p += 1;
    } while (cur != 1);

    vector<long long> fact(m + 1), invfact(m + 1), inv(m + 1);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= m; ++i) {
        inv[i] = (i == 1) ? 1 : p - p / i * inv[p % i] % p;
        fact[i] = fact[i - 1] * i % p;
        invfact[i] = invfact[i - 1] * inv[i] % p;

        assert(i * inv[i] % p == 1);
    }

    long long ans = 0;
    vector<long long> res;
    for (int i = 0; i < min(n, m + 1); ++i) {
        ans += fact[m] * invfact[i] % p * invfact[m - i] % p;
        res.push_back(ans);
    }
    res.resize(n, ans);
    reverse(all(res));
    for (auto x : res) {
        cout << pw(a, x, q) << " ";
    }
    cout << "\n";
}