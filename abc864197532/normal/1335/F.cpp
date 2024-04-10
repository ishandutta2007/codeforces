#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<lli,lli>
#define X first
#define Y second
const int mod = 998244353;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

vector <vector <bool>> vis;
vector <vector <int>> dis, mov;
vector <string> color;
int ans1 = 0, ans2 = 0, n, m;
vector <pii> v;

void dfs(int i, int j) {
    vis[i][j] = true;
    int x = i + dx[mov[i][j]], y = j + dy[mov[i][j]];
    if (x < 0 or x >= n or y < 0 or y >= m) return;
    if (vis[x][y]) {
        v.pb({x, y});
    } else {
        dfs(x, y);
    }
}

void bfs(int i, int j) {
    queue <pair <pii, int>> q;
    vector <pii> tmp;
    q.push({{i, j}, 0});
    dis[i][j] = 0;
    int cycle = 864197532;
    int x, y, d;
    while (q.size()) {
        tie(x, y) = q.front().X; d = q.front().Y; q.pop();
        tmp.eb(x, y);
        fop (k,0,4) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (mov[nx][ny] == (k ^ 1)) {
                if (dis[nx][ny] != -1) {
                    cycle = min(cycle, d + 1);
                } else {
                    q.push({{nx, ny}, d + 1});
                    dis[nx][ny] = d + 1;
                }
            }
        }
    }
    vector <int> pre(cycle, 0);
    for (auto A : tmp) {
        if (color[A.X][A.Y] == '0') pre[dis[A.X][A.Y] % cycle] = 1;
    }
    ans1 += cycle;
    ans2 += accumulate(pre.begin(), pre.end(), 0);
}

void solve() {
    cin >> n >> m;
    string tmp;
    ans1 = ans2 = 0;
    color.resize(n);
    v.clear();
    mov.assign(n, vector <int> (m));
    dis.assign(n, vector <int> (m, -1));
    vis.assign(n, vector <bool> (m, false));
    fop (i,0,n) cin >> color[i];
    fop (i,0,n) {
        cin >> tmp;
        fop (j,0,m) {
            if (tmp[j] == 'L') mov[i][j] = 1;
            if (tmp[j] == 'R') mov[i][j] = 0;
            if (tmp[j] == 'U') mov[i][j] = 3;
            if (tmp[j] == 'D') mov[i][j] = 2;
        }
    }
    fop (i,0,n) fop (j,0,m) if (!vis[i][j]) dfs(i, j);
    for (auto A : v) if (dis[A.X][A.Y] == -1) bfs(A.X,  A.Y);
    cout << ans1 << ' ' << ans2 << '\n';
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}