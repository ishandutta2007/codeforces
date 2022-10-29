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
const int inf = 1e9;
const ll llinf = 1e18, mod = (ll)(1e9) + 7;

template<typename T> bool uin(T & a, T b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> bool uax(T & a, T b) {if (b > a) {a = b; return 1;} return 0;}

mt19937 rnd(time(NULL));
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n), s(n), mx(m, -1);
    forn(i, n) cin >> p[i];
    forn(i, n) { cin >> s[i]; s[i]--;}
    forn(i, n)
    uax(mx[s[i]], p[i]);
    vector<int> c(k);
    forn(i, k) {cin >> c[i]; c[i]--;}
    int ans = 0;
    forn(i, k) {
        if (p[c[i]] < mx[s[c[i]]])
            ans++;
    }
    cout << ans;
    return 0;
}