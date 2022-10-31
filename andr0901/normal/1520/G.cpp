//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

#define int long long

constexpr int INF = 1e18;

int n, m, w;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

vector<vector<int>> a;

vector<vector<int>> bfs(pii st) {
    vector<vector<int>> dst(n, vector<int> (m, INF));
    dst[st.fs][st.sc] = 0;
    deque<pii> q = {st};
    while (!q.empty()) {
        auto v = q.front();
        q.pop_front();
        forn (k, 0, 4) {
            pii u = {v.fs + dx[k], v.sc + dy[k]};
            if (0 <= u.fs && u.fs < n &&
                0 <= u.sc && u.sc < m &&
                a[u.fs][u.sc] != -1 &&
                dst[v.fs][v.sc] + w < dst[u.fs][u.sc]) {
                q.pb(u);
                dst[u.fs][u.sc] = dst[v.fs][v.sc] + w;
            }
        }
    }
    return dst;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> w;
    a.resize(n, vector<int> (m));
    cin >> a;
    auto forw = bfs({0, 0});
    auto backw = bfs({n - 1, m - 1});
    int best_portal = INF;
    forn (i, 0, n)
        forn (j, 0, m)
            if (a[i][j] > 0)
                chkmin(best_portal, backw[i][j] + a[i][j]);
    forn (i, 0, n)
        cerr << backw[i] << "\n";
    int ans = forw[n - 1][m - 1];
    forn (i, 0, n) {
        forn (j, 0, m) {
            if (a[i][j] > 0) {
                chkmin(ans, best_portal + forw[i][j] + a[i][j]);
            }
        }
    }
    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}