#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int H; int W; int q; int p;
	while (~scanf("%d%d%d%d", &H, &W, &q, &p)) {
		vector<string> grid(H);
		rep(i, H) {
			char buf[251];
			scanf("%s", buf);
			grid[i] = buf;
		}
		vector<int> que;
		vector<int> level(H * W, -1);
		vector<ll> total(H * W, 0);
		rep(si, H) rep(sj, W) if(isalpha(grid[si][sj])) {
			que.clear();
			que.push_back(si * W + sj);
			level[si * W + sj] = q * (grid[si][sj] - 'A' + 1);
			for (int qh = 0; qh != que.size(); ++ qh) {
				int i = que[qh] / W, j = que[qh] % W;
				if (level[i * W + j] == 1) continue;
				static const int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
				for (int d = 0; d < 4; ++ d) {
					int yy = i + dy[d], xx = j + dx[d];
					if (yy < 0 || yy >= H || xx < 0 || xx >= W) continue;
					if (grid[yy][xx] == '*') continue;
					if (level[yy * W + xx] != -1) continue;
					level[yy * W + xx] = level[i * W + j] / 2;
					que.push_back(yy * W + xx);
				}
			}
			for (int u : que) {
				total[u] += level[u];
				level[u] = -1;
			}
		}
		int ans = 0;
		rep(u, H * W)
			ans += total[u] > p;
		printf("%d\n", ans);
	}
	return 0;
}