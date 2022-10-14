#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 287, logN = 17;

int dis[N][N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) dis[i][j] = (i == j ? 0 : 1 << 29);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << "YES\n0\n0\n";
        return 0;
    }
    vector <pii> E;
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        if (w) {
            dis[v][u] = -1;
            dis[u][v] = 1;
        } else {
            dis[v][u] = 1;
            dis[u][v] = 1;
        }
        E.eb(u, v);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                if (dis[i][j] < -1 << 30) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dis[i][i] < 0) {
            cout << "NO\n";
            return 0;
        }
    }
    pii dia = mp(0, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dia = max(dia, mp(dis[i][j], i));
        }
    }
    int rt = dia.Y;
    for (pii A : E) {
        if (dis[rt][A.X] == dis[rt][A.Y]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n" << dia.X << endl;
    for (int i = 0; i < n; ++i) cout << dis[rt][i] << " \n"[i == n - 1];
}