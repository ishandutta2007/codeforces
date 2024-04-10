#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstring>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <ctime>
#include <climits>
#include <cassert>
#define fr first
#define sc second
#define mk make_pair
#define ad push_back
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define lli long long int
#define y1 arayikhalatyan
#define j1 jiglypuff
#define ld long double
#define itn int
#define pii pair<int, int> 
#define all(x) (x).begin(), (x).end()
using namespace std;

lli gcd(lli a, lli b) { return (b == 0LL ? a : gcd(b, a % b)); }
ld dist(ld x1, ld y1, ld x2, ld y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
lli S(lli a)
{
	return (a * (a + 1LL)) / 2;
}
char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };


const int N = 1110;
const int M = 45;
const lli mod = 1e9 + 7;
const ld pi = acos(-1);
const int T = 238;
const ld e = 74e-9;

lli bp(lli a, lli b = -2LL)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret *= a, ret %= mod;
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}

int n, m;
int dis[M][N][N], vis[N][N], vc[M];
int k, c[N][N];
vector<pii> g[M];
void bfs(int col)
{
    //cout << col << "----" << endl;
    queue<pii> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            vis[i][j] = 0, dis[col][i][j] = 1e9;
    for (int i = 1; i <= k; i++)
        vc[i] = 0;
    for (pii s : g[col])
    {
        dis[col][s.first][s.second] = 0;
        vis[s.first][s.second] = 1;
        q.push(s);
    }

    vc[col] = 1;
    while (!q.empty())
    {
        pii now = q.front();
        int x = now.first;
        int y = now.second;
        q.pop();
        if (!vc[c[x][y]])
        {

            for (pii s : g[c[x][y]])
            {
                if (!vis[s.first][s.second])
                {
                    dis[col][s.first][s.second] = min(dis[col][s.first][s.second], dis[col][x][y] + 1);
                    q.push(mk(s.first, s.second));
                    vis[s.first][s.second] = 1;
                }
            }
            vc[c[x][y]] = 1;
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy])
            {
                dis[col][xx][yy] = min(dis[col][xx][yy], dis[col][x][y] + 1);
                vis[xx][yy] = 1;
                q.push(mk(xx, yy));
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            g[c[i][j]].push_back(mk(i, j));
        }
    for (int i = 1; i <= k; i++)
        bfs(i);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = abs(x1 - x2) + abs(y1 - y2);
        for (int j = 1; j <= k; j++)
            ans = min(ans, dis[j][x1][y1] + dis[j][x2][y2] + 1);

        cout << ans << "\n";
    }
}