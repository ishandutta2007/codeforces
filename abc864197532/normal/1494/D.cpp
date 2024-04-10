#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 501, K = 111;

int ans[N << 2], a[N][N], t;
vector <pii> edge;

int solve(vector <int> p) {
    if (p.size() == 1) {
        ans[p[0]] = a[p[0]][p[0]];
        return p[0];
    }
    int mx = 0;
    for (int i : p) for (int j : p) mx = max(mx, a[i][j]);
    vector <bool> vis(N, false);
    vector <int> cc;
    function<void(int)> dfs = [&](int v) {
        vis[v] = true;
        cc.pb(v);
        for (int u : p) if (!vis[u] && a[v][u] != mx) {
            dfs(u);
        }
    };
    int rt = t++;
    ans[rt] = mx;
    for (int i : p) if (!vis[i]) {
        dfs(i);
        int to = solve(cc);
        edge.eb(to, rt);
        cc.clear();
    }
    return rt;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    t = n;
    vector <int> cur(n);
    iota(all(cur), 0);
    int rt = solve(cur);
    cout << t << endl;
    for (int i = 0; i < t; ++i) cout << ans[i] << " \n"[i == t - 1];
    cout << rt + 1 << endl;
    for (pii A : edge) cout << A.X + 1 << ' ' << A.Y + 1 << endl;
}