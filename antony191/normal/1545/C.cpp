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
const int inf = 1000'000'000, mod = 1000000007, mod2 = 998244353;
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

const int N = 501;
int a[N + N][N], cnt[N][N];
vector<int> g[N][N], h[N + N], order, cl;
void dfs(int v, int c = 0) {
    cl[v] = c;
    if (c == 0) {
        order.push_back(v);
    }
    for (auto to : h[v]) {
        if (cl[to] == -1) {
            cl[to] = 1 - c;
            dfs(to, 1 - c);
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt[i][j] = 0;
                g[i][j].clear();
            }
        }
        for (int i = 0; i < n + n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                cnt[j][--a[i][j]]++;
                g[j][a[i][j]].push_back(i);
            }
        }
        vector<int> chosen(n + n);
        vector<int> answer, bad;
        int it1 = 0, it2 = 0;
        for (int i = 0; i < n + n; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt[j][a[i][j]] == 1)
                    chosen[i] = 1;
            }
            if (chosen[i] == 1) {
                answer.push_back(i);
            }
        }
        while(it1 < (int)answer.size() || it2 < (int)bad.size()) {
            if (it1 < (int)answer.size()) {
                int i = answer[it1++];
                for (int j = 0; j < n; j++) {
                    for (auto k : g[j][a[i][j]]) {
                        if (chosen[k] == 0) {
                            chosen[k] = -1;
                            bad.push_back(k);
                        }
                    }
                }
            } else {
                int i = bad[it2++];
                for (int j = 0; j < n; j++) {
                    if (--cnt[j][a[i][j]] == 1) {
                        for (auto k : g[j][a[i][j]]) {
                            if (chosen[k] == 0) {
                                chosen[k] = 1;
                                answer.push_back(k);
                            }
                        }
                    }
                }
            }
        }
        int ans = 1;
        if ((int)answer.size() < n) {
            for (int i = 0; i < n + n; i++) {
                h[i].clear();
            }
            cl.assign(n + n, -1);
            for (int j = 0; j < n; j++) {
                for (int c = 0; c < n; c++) {
                    vector<int> tmp;
                    for (auto k : g[j][c]) {
                        if (chosen[k] == 0)
                            tmp.push_back(k);
                    }
                    if ((int)tmp.size() == 2) {
                        h[tmp[0]].push_back(tmp[1]);
                        h[tmp[1]].push_back(tmp[0]);
                    }
                }
            }
            for (int i = 0; i < n + n; i++) {
                if (chosen[i] || cl[i] != -1) continue;
                order.clear();
                dfs(i, 0);
                for (auto k : order) {
                    answer.push_back(k);
                }
                ans = ans * 2ll % mod2;
            }
        }
        cout << ans << el;
        for (int i = 0; i < n; i++) {
            cout << answer[i] + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}