#include<bits/stdc++.h>
#define ll long long
#define N 55
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
int n, a[N][N];
map<pair<pii, pii>, bool> M;
int dx[] = {2, -2, 0, 0, 1, -1};
int dy[] = {0, 0, 2, -2, 1, -1};
bool valid(int x, int y) {
	return 1 <= min(x, y) && max(x, y) <= n;
}
bool query(int sx, int sy, int nx, int ny) {
	if(sx > nx) swap(sx, nx), swap(sy, ny);
	if(sy > ny) swap(sx, nx), swap(sy, ny);
	assert(sx <= nx && sy <= ny);
	if(M.count(mp(mp(sx, sy), mp(nx, ny))) > 0) return M[mp(mp(sx, sy), mp(nx, ny))];
	printf("? %d %d %d %d\n", sx, sy, nx, ny);
	fflush(stdout);
	int o;
	scanf("%d", &o);
	return M[mp(mp(sx, sy), mp(nx, ny))] = o;
}
queue<pii> q;
void bfs(int x, int y) {
	q.push(mp(x, y));
	while(SZ(q)) {
		int ux = q.front().fi, uy = q.front().se;
		q.pop();
		rep(d, 0, 5) {
			int nx = ux + dx[d], ny = uy + dy[d];
			if(!valid(nx, ny) || ~a[nx][ny]) continue;
			int o = query(ux, uy, nx, ny);
			a[nx][ny] = a[ux][uy] ^ o ^ 1;
			q.push(mp(nx, ny)); 
		}
	}
}
void output(int o) {
	printf("!\n");
	rep(i, 1, n) {
		rep(j, 1, n) {
			if((i + j) % 2) printf("%d", a[i][j] ^ o);
			else printf("%d", a[i][j]);
		}
		printf("\n");
	}
	exit(0);
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	memset(a, -1, sizeof a);
	a[1][1] = 1;
	a[n][n] = 0;
	bfs(1, 1);
	a[1][2] = 1;
	bfs(1, 2);
	rep(i, 1, n) rep(j, 1, n) {
		if(!valid(i - 1, j + 1) || a[i][j] == a[i - 1][j + 1]) continue;
		if(valid(i - 1, j - 1)) {
			int o = query(i - 1, j - 1, i, j + 1);
			output(a[i - 1][j - 1] ^ a[i][j + 1] ^ o ^ 1);
		} else {
			int o = query(i - 1, j, i, j + 2);
			output(a[i - 1][j] ^ a[i][j + 2] ^ o ^ 1);
		}
	}
	rep(i, 1, n - 2) {
		if(a[i][i] == a[i + 2][i + 2]) continue;
		if(a[i][i] == a[i + 1][i + 1]) {
			/*
				a a
				 a 
				a b
			*/ 
			if(a[i + 1][i] == a[i + 2][i + 1]) {
				int o = query(i, i, i + 2, i + 1);
				output(a[i][i] ^ a[i + 2][i + 1] ^ o ^ 1);
			} else {
				int o = query(i, i + 1, i + 2, i + 2);
				output(a[i][i + 1] ^ a[i + 2][i + 2] ^ o ^ 1);
			}
		} else {
			/*
				a b
				 b 
				b b
			*/ 
			if(a[i + 1][i] == a[i + 2][i + 1]) {
				int o = query(i, i + 1, i + 2, i + 2);
				output(a[i][i + 1] ^ a[i + 2][i + 2] ^ o ^ 1);
			} else {
				int o = query(i, i, i + 2, i + 1);
				output(a[i][i] ^ a[i + 2][i + 1] ^ o ^ 1);
			}
		}
	}
	return 0;
}
/*
111
110
100
*/