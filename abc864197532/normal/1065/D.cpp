#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 10, logN = 18, K = 350;

int dis[3][N][N][N][N], dx[8] = {1, 1, 2, 2, -1, -1, -2, -2}, dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int xx[4] = {1, 1, -1, -1}, yy[4] = {-1, 1, -1, 1};

void bfs(int a, int b, int n) {
	fop (i,0,n) fop (j,0,n) dis[0][a][b][i][j] = 100000;
	queue <pii> q;
	q.push({a, b});
	dis[0][a][b][a][b] = 0;
	int x, y;
	while (q.size()) {
		tie(x, y) = q.front(); q.pop();
		fop (i,0,8) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dis[0][a][b][nx][ny] == 100000) {
				dis[0][a][b][nx][ny] = dis[0][a][b][x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

void bfs2(int a, int b, int n) {
	fop (i,0,n) fop (j,0,n) dis[1][a][b][i][j] = 100000;
	queue <pii> q;
	q.push({a, b});
	dis[1][a][b][a][b] = 0;
	int x, y;
	while (q.size()) {
		tie(x, y) = q.front(); q.pop();
		int nx = x, ny = y;
		fop (i,0,4) {
			tie(nx, ny) = mp(x, y);
			while (true) {
				nx += xx[i], ny += yy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
				if (dis[1][a][b][nx][ny] == 100000) {
					dis[1][a][b][nx][ny] = dis[1][a][b][x][y] + 1;
					q.push({nx, ny});
				}
			}
		}
		
	}
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, tmp;
    cin >> n;
    fop (i,0,n) fop (j,0,n) bfs(i, j, n);
    fop (i,0,n) fop (j,0,n) bfs2(i, j, n);
    fop (i,0,n) fop (j,0,n) fop (ii,0,n) fop (jj,0,n) dis[2][i][j][ii][jj] = (i != ii) + (j != jj);
	vector <pii> pos(n * n);
    fop (i,0,n) fop (j,0,n) {
    	cin >> tmp;
    	pos[tmp - 1] = mp(i, j);
	}
	pii dp[n * n][3];
	dp[0][0] = dp[0][1] = dp[0][2] = mp(0, 0);
	fop (i,1,n * n) fop (j,0,3) {
		dp[i][j] = mp(1 << 30, 0);
		int x, y, nx, ny;
		tie(x, y) = pos[i - 1];
		tie(nx, ny) = pos[i];
		fop (k,0,3) {
			fop (ii,0,n) fop (jj,0,n) dp[i][j] = min(dp[i][j], mp(dp[i - 1][k].X + dis[k][x][y][ii][jj] + dis[j][ii][jj][nx][ny] + (k != j), dp[i - 1][k].Y + (k != j)));
		}
	}
	pii ans = mp(1 << 30, 0);
	fop (j,0,3) ans = min(ans, dp[n * n - 1][j]);
	cout << ans.X << ' ' << ans.Y << endl;
}