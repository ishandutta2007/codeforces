#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")

using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)


typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9, p = 41;
const ll llinf = 1e18, mod = (ll)(1e9) + 7;
template<typename T> bool uin(T & a, T b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> bool uax(T & a, T b) {if (b > a) {a = b; return 1;} return 0;}

mt19937 rnd(time(NULL));

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<int> dp(n, inf);
    dp[0] = a;
    string t = s;
    vector<int> z(n);
    forn(i, n - 1) {
        if (i > 0) uin(dp[i], dp[i - 1] + a);
        for (int j = i + 1; j < n; ++j)
            t[j - i - 1] = s[j];
        forn(j, i + 1)
        t[j + (n - i - 1)] = s[j];
        z.assign(n, 0);
        for (int j = 1, l = 0, r = 0; j < n; ++j) {
            if (r >= j)
                z[j] = min(z[j - l], r - j + 1);
            while(j + z[j] < n && t[z[j]] == t[z[j] + j])
                z[j]++;
            if (j + z[j] > r)
                l = j, r = j + z[j] - 1;
        }
        int mx = 0;
        for (int j = n - i - 1; j < n; ++j)
            uax(mx, z[j]);
        uin(mx, n - i - 1);
        for (int j = i + 1; j <= i + mx; ++j)
            uin(dp[j], dp[i] + b);
    }
    if (n > 1)
    uin(dp[n - 1], dp[n - 2] + a);
    cout << dp[n - 1];
    return 0;
}