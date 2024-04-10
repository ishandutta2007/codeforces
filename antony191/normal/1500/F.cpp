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
const int inf = 1000'000'000, mod = 1000'000'007, mod2 = 998'244'353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

//#define forn(i, n) for (int i = 0; i < (int)n; ++i)
//#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define firn(i, n) for (int (i) = 1; (i) != (n); (i)++)
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

const int N = 1000'001;
vector<int> r[N];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll C;
    cin >> n >> C;
    vector<ll> w(n - 2);
    vector<ll> pref(n - 1);
    set<pair<ll, int>> q[2];
    forn(i, n - 2) cin >> w[i];
    forn(i, n - 2) {
        pref[i + 1] = w[i] - pref[i];
    }
    vector<pair<ll, ll>> g(n - 2, {-1, -1});
    g[0] = {0, w[0]};
    int p;
    firn(i, n - 2) {
        p = i & 1;
        auto j = q[1 - p].end();
        while(!q[1 - p].empty() && q[1 - p].rbegin()->x > pref[i + 1]) {
            r[i].push_back(q[1 - p].rbegin()->y);
            j = q[1 - p].end();
            j--;
            q[1 - p].erase(j);
        }
        while(!q[p].empty() && q[p].begin()->x + pref[i + 1] < 0) {
            r[i].push_back(q[p].begin()->y);
            q[p].erase(q[p].begin());
        }
        if ((g[i - 1].x <= w[i] && w[i] <= g[i - 1].y) || (!q[p].empty() && q[p].begin()->x + pref[i + 1] == 0) || (!q[1 - p].empty() && q[1 - p].rbegin()->x == pref[i + 1])) {
            g[i] = {0, w[i]};
        } else if (g[i - 1].x != -1 && g[i - 1].x <= w[i]) {
            g[i] = {w[i] - g[i - 1].y, w[i] - g[i - 1].x};
        }
        if (g[i].x == -1 && q[0].empty() && q[1].empty())
            return cout << "No" << el, 0;
        q[p].emplace(pref[i], i);
    }
    vector<ll> ans(n);
    ll t = w[n - 3];
    ans[n - 2] = t;
    ll tmp;
    for (int i = n - 3; i >= 0; i--) {
        p = i & 1;
        for (auto j : r[i]) q[j & 1].emplace(pref[j], j);
        q[p].erase({pref[i], i});
        if (i == 0) {
            t = t > 0 ? -w[i] : w[i];
            ans[0] = ans[1] + t;
            break;
        }
        if (abs(t) == w[i]) {
            if (g[i - 1].x != -1 && g[i - 1].x <= w[i]) {
                t = t > 0 ? -g[i - 1].x : g[i - 1].x;
            } else
            if (!q[p].empty() && pref[i] - q[p].rbegin()->x <= w[i]) {
                tmp = pref[i] - q[p].rbegin()->x;
                t = t > 0 ? -tmp : tmp;
            } else {
                tmp = pref[i] + q[1 - p].begin()->x;
                t = t > 0 ? -tmp : tmp;
            }
        } else {
            ll t1 = w[i] - abs(t);
            if (g[i - 1].x <= w[i] && w[i] <= g[i - 1].y) {
                t = t > 0 ? -w[i] : w[i];
            } else if (g[i - 1].x <= t1 && t1 <= g[i - 1].y) {
                t = t > 0 ? t1 : -t1;
            } else {
                auto j = q[p].lower_bound(pair<ll, int>{pref[i] - w[i], 0});
                if (j != q[p].end() && j->x == pref[i] - w[i]) t = t > 0 ? -w[i] : w[i];
                else {
                    j = q[1 - p].lower_bound(pair<ll, int>{w[i] - pref[i], 0});
                    if (j != q[1 - p].end() && j->x == w[i] - pref[i]) t = t > 0 ? -w[i] : w[i];
                    else {
                        j = q[p].lower_bound(pair<ll, int>{pref[i] - t1, 0});
                        if (j != q[p].end() && j->x == pref[i] - t1) t = t > 0 ? t1 : -t1;
                        else {
                            j = q[1 - p].lower_bound(pair<ll, int>{t1 - pref[i], 0});
                            if (j != q[1 - p].end() && j->x == t1 - pref[i]) t = t > 0 ? t1 : -t1;
                        }
                    }
                }
            }
        }
        ans[i] = ans[i + 1] + t;
    }
    ll mn = llinf;
    forn(i, n) uin(mn, ans[i]);
    forn(i, n) ans[i] -= mn;
    cout << "Yes" << el;
    output(ans);
    return 0;
}