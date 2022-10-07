#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 1005
#define INF 0x3f3f3f3f
const int d[8][2] = {{-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {1, 2}, {1, -2}, {2, -1}, {2, 1}};
struct node{
	int x, y;
	void get(){ x = read(), y = read(); }
}w, b;
int n, m, dis[2][N][N], h, t;
node pre[2][N][N];
node Q[N * N];
void bfs(int k, int x, int y){
	memset(dis[k], 0x3f, sizeof dis[k]);
	h = 0, t = 1, Q[t] = (node){x, y}, dis[k][x][y] = 0;
	while (h < t){
		node u = Q[++h];
		for (register int i = 0; i < 8; ++i){
			node v = u;
			v.x += d[i][0], v.y += d[i][1];
			if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && dis[k][v.x][v.y] == INF)
				dis[k][v.x][v.y] = dis[k][u.x][u.y] + 1, pre[k][v.x][v.y] = u, Q[++t] = v;
		}
	}
}
node A, B;
void check(){
	for (register int i = 0; i < 8; ++i)
		if (A.x + d[i][0] == B.x && A.y + d[i][1] == B.y)
			printf("%d %d\n", B.x, B.y), fflush(stdout), exit(0);
}
void move(){
	printf("%d %d\n", A.x, A.y), fflush(stdout), B.get(), check();
}
void solve1(int k){
	if (!k) printf("WHITE\n"), fflush(stdout), A = w, B = b, check();
	else printf("BLACK\n"), fflush(stdout), A = b, B.get(), check();
	if (!dis[k][A.x][A.y]) exit(0);
	while (1){
		A = pre[k][A.x][A.y];
		if (!dis[k][A.x][A.y]) printf("%d %d\n", A.x, A.y), fflush(stdout), exit(0);
		move();
	}
}
void solve2(int k){
	if (!k) printf("WHITE\n"), fflush(stdout), A = w, B = b, check();
	else printf("BLACK\n"), fflush(stdout), A = b, B.get(), check();
	while (1){
		if (dis[k ^ 1][A.x][A.y] == 0) break;
		A = pre[k ^ 1][A.x][A.y], move();
	}
	if (!k) --A.x, ++A.y, ++A.y, move(), --A.x, --A.x, --A.y, move(), ++A.x, ++A.x, --A.y;
	else ++A.x, ++A.y, ++A.y, move(), ++A.x, ++A.x, --A.y, move(), --A.x, --A.x, --A.y;
	printf("%d %d\n", A.x, A.y), fflush(stdout), exit(0);
}
int main(){
	n = read(), m = read(), w.get(), b.get();
	bfs(0, n >> 1, m >> 1), bfs(1, (n >> 1) + 1, m >> 1);
	int colw = (w.x & 1) == (w.y & 1), colb = (b.x & 1) == (b.y & 1);
	if (colw != colb){
		if (dis[0][w.x][w.y] <= dis[1][b.x][b.y]) solve1(0);
		else if (dis[1][w.x][w.y] >= dis[1][b.x][b.y] + 2) solve1(1);
		else solve2(0);
	}
	else{
		if (dis[1][b.x][b.y] <= dis[0][w.x][w.y] - 1) solve1(1);
		else if (dis[0][b.x][b.y] >= dis[0][w.x][w.y] + 1) solve1(0);
		else solve2(1);
	}
}