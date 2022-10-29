#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 1000'000'007;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

vector<int> a[3];
int n[3];
void chkmin(ll &ans, int a, int b, int c) {
    uin(ans, (a - b) * 1ll * (a - b) + (a - c) * 1ll * (a - c) + (b - c) * 1ll * (b - c));
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        forn(i, 3) cin >> n[i];
        forn(i, 3) {
            a[i].resize(n[i]);
            forn(j, n[i])
                cin >> a[i][j];
            sort(all(a[i]));
        }
        ll ans = 5ll * llinf;
        forn(i, 3) forn(j, n[i]) {
            int k = (i > 0 ? 0 : 1);
            int l = 3 - k - i;
            auto s = lower_bound(all(a[k]), a[i][j]),
                t = lower_bound(all(a[l]), a[i][j]);
            if (s == a[k].end() || t == a[l].end()) continue;
            chkmin(ans, *s, *t, a[i][j]);
            if (*s < *t) {
                auto q = lower_bound(all(a[k]), (a[i][j] + *t) / 2);
                if (q < a[k].end()) chkmin(ans, *q, *t, a[i][j]);
                q--;
                if (q >= a[k].begin()) chkmin(ans, *q, *t, a[i][j]);
            }
            else
            if (*t < *s) {
                auto q = lower_bound(all(a[l]), (a[i][j] + *s) / 2);
                if (q < a[l].end()) chkmin(ans, *s, *q, a[i][j]);
                q--;
                if (q >= a[l].begin()) chkmin(ans, *s, *q, a[i][j]);
            }
        }
        cout << ans << el;
    }
    return 0;
}