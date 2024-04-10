#include<bits/stdc++.h>
#define ll long long
#define N 100115
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int B = 100;
int n, m, q, G[N][15];
pii to[N][15];
bool vis[N][15];
char s[15];
int dx[] = {0, -1, 0}, dy[] = {-1, 0, 1};
int fuck(char ch) {
	if(ch == '<') return 0;
	if(ch == '^') return 1;
	if(ch == '>') return 2;
	return 114514;
}
bool valid(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
pii dfs(int x, int y, int up) {
	if(x < up || !valid(x, y)) return mp(x, y);
	if(to[x][y] != mp(0, 0)) return to[x][y];
	vis[x][y] = 1;
	int nx = x + dx[G[x][y]], ny = y + dy[G[x][y]];
	if(vis[nx][ny]) to[x][y] = mp(-1, -1);
	else to[x][y] = dfs(nx, ny, up);
	vis[x][y] = 0;
	return to[x][y];
}
void recalc(int id) {
	int l = (id - 1) * B + 1, r = min(n, l + B - 1);
	// printf("%d %d\n", l,r);
	rep(i, l, r) rep(j, 1, m) to[i][j] = mp(0, 0);
	rep(i, l, r) rep(j, 1, m) if(to[i][j] == mp(0, 0)) dfs(i, j, l);
}
int main(){
	// freopen("data.in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &q);
	rep(i, 1, n) {
		scanf("%s", s + 1);
		rep(j, 1, m) G[i][j] = fuck(s[j]);
	}
	rep(i, 1, n) rep(j, 1, m) to[i][j] = mp(0, 0);
	rep(i, 1, (n + B - 1) / B) recalc(i);
	while(q--) {
		// rep(i, 1, n) {
		// 	rep(j, 1, m) printf("(%d %d) ", to[i][j].fi, to[i][j].se);
		// 	printf("\n");
		// }
		char lzjak[3];
		int x, y;
		scanf("%s", lzjak);
		if(lzjak[0] == 'A') {
			scanf("%d%d", &x, &y);
			while(1) {
				pii nxt = to[x][y];
				if(!valid(nxt.fi, nxt.se) || nxt == mp(-1, -1)) {
					x = nxt.fi; y = nxt.se;
					break;
				}
				x = nxt.fi; y = nxt.se;
			}
			printf("%d %d\n", x, y);
		} else {
			scanf("%d%d%s", &x, &y, lzjak);
			G[x][y] = fuck(lzjak[0]);
			int bel = (x + B - 1) / B;
			recalc(bel);
		}
	}
	return 0;
}