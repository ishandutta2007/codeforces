#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
int dis[2020][2020];
string c[2020];
pair<int, int> fr[2020][2020];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int dir[] = {'>', '<', 'v', '^'};
void bfs(int X, int Y) {
    dis[X][Y] = 0;
    queue< pair<int, int> > Q;
    Q.push(make_pair(X, Y));
    while(Q.size() > 0) {
        int a = Q.front().first;
        int b = Q.front().second;
        Q.pop();
        for(int k = 0; k < 4; k++) {
            int x = a + dx[k];
            int y = b + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && c[x][y] == dir[k] && dis[x][y] == -1) {
                dis[x][y] = dis[a][b] + 1;
                if(c[a][b] == '#') fr[x][y] = make_pair(x, y);
                else fr[x][y] = fr[a][b];
                Q.push(make_pair(x, y));
            }
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    memset(dis, -1, sizeof dis);
    memset(fr, -1, sizeof fr);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c[i][j] == '#') {
                bfs(i, j);
            }
        }
    }
    int mx = 0;
    pair<int, int> b;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dis[i][j] == -1) {
                cout << -1 << "\n";
                return;
            }
            if(mx < dis[i][j]) {
                mx = dis[i][j];
                b = fr[i][j];
            }
        }
    }
    if(mx == 0) {
        cout << 0 << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dis[i][j] == -1) {
                cout << -1 << "\n";
                return;
            }
            if(mx == dis[i][j] && fr[i][j] != b) {
                cout << 2 * mx << "\n";
                return;
            }
        }
    }
    cout << 2 * mx - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}