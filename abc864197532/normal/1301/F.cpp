#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>
#define pli pair<lli,int> 
#define X first
#define Y second
int n, m, c;
vector <pii> point[40];
int dp[1000][1000][40], color[1000][1000];
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

void bfs(int k) {
    queue <pair <pii, int>> q;
    for (pii A : point[k]) {
        dp[A.X][A.Y][k] = 0;
        q.push({A, 0});
    }
    bool vis[c];
    fop (i,0,c) vis[i] = false;
    vis[k] = true;
    pii A;
    int d;
    while (q.size()) {
        tie(A, d) = q.front(); q.pop();
        if (!vis[color[A.X][A.Y]]) {
            vis[color[A.X][A.Y]] = true;
            for (pii B : point[color[A.X][A.Y]]) {
                if (dp[B.X][B.Y][k] > d + 1) {
                    dp[B.X][B.Y][k] = d + 1;
                    q.push({B, d + 1});
                }
            }
        }
        fop (i,0,4) {
            int x = A.X + dx[i], y = A.Y + dy[i];
            if (x < 0 or x >= n or y < 0 or y >= m) continue;
            if (dp[x][y][k] > d + 1) {
                dp[x][y][k] = d + 1;
                q.push({{x, y}, d + 1});
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> c;
    fop (i,0,n) {
        fop (j,0,m) {
            cin >> color[i][j];
            color[i][j]--;
            point[color[i][j]].eb(i, j);
        }
    }
    fop (i,0,n) {
        fop (j,0,m) {
            fop (k,0,c) {
                dp[i][j][k] = 10000;
            }
        }
    }
    fop (i,0,c) bfs(i);
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        x2--; y2--;
        int ans = abs(x1 - x2) + abs(y1 - y2);
        fop (i,0,c) {
            ans = min(ans, dp[x1][y1][i] + 1 + dp[x2][y2][i]);
        }
        cout << ans << endl;
    }
}