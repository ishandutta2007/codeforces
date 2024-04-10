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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    vector<int> t(k, -1);
    vector<bool> ans(n, 0);
    vector<int> nach(n);
    int m1 = 0, m2;
    for (int i = 0; ; i++) {
        if (m2 == n) break;
        forn(j, k)
        if (t[j] == -1 || nach[t[j]] + a[t[j]] == i) {
            if (t[j] != -1) m2++;
            if (m1 < n) {
            t[j] = m1;
            nach[m1] = i;
            m1++;
            }
            else t[j] = -1;
        }
        int rn = trunc(0.5 + 100.0 * (ld)m2 / (ld)n);
        forn(j, k)
        if (i - nach[t[j]] + 1 == rn) {
            ans[t[j]] = 1;
        }
    }
    int cnt = 0;
    forn(i, n) cnt += ans[i];
    cout << cnt;
    return 0;
}