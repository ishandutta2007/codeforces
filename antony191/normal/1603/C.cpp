#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

const char el = '\n';
const int inf = 1000000001, mod = 1000000007, mod2 = 998244353, p = 37;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
//#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
//#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));
mt19937_64 rnd_64(time(nullptr));

const int N = 100'001;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> tmp;
    vector<pair<int, int>> g1, g2;
    while(t--) {
        int ans = 0;
        int n;
        cin >> n;
        vector<int> a(n);
        forn(i, n) cin >> a[i];
        forn(i, n) {
            g2.clear();
            for (int j = 1; ; j++) {
                g2.emplace_back(j, 0);
                tmp.push_back((a[i] - 1) / j + 1);
                if (j * j >= a[i]) break;
            }
            reverse(all(tmp));
            for (auto to : tmp) {
                g2.emplace_back(to, 0);
            }
            sort(all(g2));
            tmp.clear();
//            g[i].resize(unique(all(g[i])) - g[i].begin());
            int it = 0;
            forn(j, g2.size()) {
                g2[j].y = (i + 1) * 1ll * (g2[j].x - 1) % mod2;
                if (i > 0) {
                    int tt = (a[i - 1] - 1) / (a[i] / g2[j].x) + 1;
                    while (g1[it].x != tt) it++;
                    g2[j].y = (g2[j].y + g1[it].y) % mod2;
                }
            }
            ans = (ans + g2[0].y) % mod2;
            g1 = g2;
        }
        cout << ans << el;
    }
    return 0;
}