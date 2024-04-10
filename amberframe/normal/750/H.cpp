#include <bits/stdc++.h>

#define pb push_back
#define rep(i, n) for (int i = 1 ; i <= (n) ; i++)
#define per(i, n) for (int i = (n) ; i >= 1 ; i--)
#define repi(n) for (int i = 1; i <= (n) ; i++)
#define mabs(n) ((n) > 0 ? (n) : (-n))
#define sqr(n) ((n) * (n))
#define print(V) for (auto v: V) printf("%d ",v)
using namespace std;
typedef pair<int, int> mp;
typedef long long LL ;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 500;

map< LL, bool> container;
int dx[] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
char str[maxn][maxn];
int id[maxn][maxn], tot, S, T, hav[maxm];
int p1[maxm], p2[maxm], n, m, q;

int stk[maxm], top, x_[maxn], y_[maxn];
int find1(int u) {return p1[u] ? p1[u] = find1(p1[u]) : u;}
int find2(int u) {return p2[u] ? p2[u] = find2(p2[u]) : u;}
void merge1(int u, int v) {u = find1(u); v = find1(v); u != v ? p1[u] = v : 0;}
void merge2(int u, int v) {stk[++top] = u, stk[++top] = v; u = find2(u); v = find2(v); u != v ? p2[u] = v : 0;}
bool inG(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m;}
void insert(int x, int y) {hav[x] = hav[y] = true; container[(LL)x * 1000000ll + y] = true;}
bool query(int x, int y) {return container[(LL)x * 1000000ll + y];}


bool check(int x, int y)
{
	if (!inG(x, y)) return false;
	if (x == 1 && y == 1) return false;
	if (x == n && y == m) return false;
	
	bool conS = false, conT = false;
	rep(k, 8)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (find2(id[nx][ny]) == find2(S)) conS = true;
		if (find2(id[nx][ny]) == find2(T)) conT = true;
	}
	return conS && conT;
}
int main()
{
	#ifdef FILE_TEST
		freopen("grid.in", "r", stdin);
	#endif
	
	scanf("%d %d %d", &n, &m, &q);
	repi(n) scanf("%s", str[i] + 1);
	S = ++tot ; T = ++tot;
	repi(n) rep(j, m) id[i][j] = ++tot;
	
	repi(m) str[0][i] = '#', id[0][i] = T;
	repi(n) str[i][0] = '#', id[i][0] = S;
	repi(m) str[n + 1][i] = '#', id[n + 1][i] = S;
	repi(n) str[i][m + 1] = '#', id[i][m + 1] = T;
	id[0][0] = ++tot; id[n + 1][m + 1] = ++tot;
	
	rep(x, n) rep(y, m) if (str[x][y] == '#') rep(k, 8)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (str[nx][ny] == '#')
			merge1(id[x][y], id[nx][ny]);
	}
	S = find1(S); T = find1(T);
	for (int x = 0 ; x <= n + 1; x++ )
	for (int y = 0 ; y <= m + 1; y++ )
		id[x][y] = find1(id[x][y]);
	
	rep(x, n) rep(y, m) rep(k1, 8) 
	{
		if (x == 1 && y == 1) continue;
		if (x == n && y == m) continue;
		int nx1 = x + dx[k1];
		int ny1 = y + dy[k1];
		if (str[nx1][ny1] != '#') continue;
		rep(k2, 8)
		{
			int nx2 = x + dx[k2];
			int ny2 = y + dy[k2];
			if (str[nx2][ny2] != '#') continue;
			int u = id[nx1][ny1];
			int v = id[nx2][ny2];
			if (u != v) insert(u, v);
		}
	}
	
	repi(q)
	{
		int r, x, y; bool OK = false;
		scanf("%d", &r);
		repi(r) scanf("%d %d", &x_[i], &y_[i]);
		repi(r) str[x_[i]][y_[i]] = '#';
		repi(r) rep(k, 8)
		{
			int nx = x_[i] + dx[k];
			int ny = y_[i] + dy[k];
			if (str[nx][ny] == '#')
				merge2(id[x_[i]][y_[i]], id[nx][ny]);
		}
		repi(r) rep(k, 8)
		{
			int nx = x_[i] + dx[k];
			int ny = y_[i] + dy[k];
			OK |= check(nx, ny);
		}
		
		OK |= find2(T) == find2(S);
		stk[++top] = S; stk[++top] = T;
		for (int i = 1; i <= top && !OK; i++) if (find2(stk[i]) == find2(S) && hav[stk[i]])
		for (int j = 1; j <= top && !OK; j++) if (find2(stk[j]) == find2(T) && hav[stk[j]])
			OK |= query(stk[i], stk[j]);
		repi(r) str[x_[i]][y_[i]] = '.';
		while (top) p2[ stk[top--]] = 0;
		printf("%s\n", OK ? "NO" : "YES");
		fflush(stdout);
	}
	return 0;
}