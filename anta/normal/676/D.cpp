#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int m;
	while(~scanf("%d%d", &n, &m)) {
		vector<string> maze(n);
		rep(i, n)
			cin >> maze[i];
		int sy; int sx;
		scanf("%d%d", &sy, &sx), -- sy, -- sx;
		int gy; int gx;
		scanf("%d%d", &gy, &gx), -- gy, -- gx;
		vector<vi> door(n, vi(m));
		const char *str = "+-|^><vLRUD*";
		const int masks[12] = {
			//RDLU
			15, 1 + 4, 2 + 8,
			8, 1, 4, 2,
			15 - 4, 15 - 1, 15 - 8, 15 - 2,
			0
		};
		rep(i, n) rep(j, m)
			door[i][j] = masks[strchr(str, maze[i][j]) - str];
		vector<bool> vis(n * m * 4);
		vi q, nq;
		nq.push_back((sy * m + sx) * 4 + 0);
		int dist = 0, ans = INF;
		while(!nq.empty()) {
			q.swap(nq);
			while(!q.empty()) {
				int s = q.back(); q.pop_back();
				if(vis[s]) continue;
				vis[s] = true;
				int i = s / 4 / m, j = s / 4 % m, t = s % 4;
				if(i == gy && j == gx) {
					nq.clear();
					ans = dist;
					break;
				}
				static const int dy[4] = { 0, 1, 0, -1 }, dx[4] = { 1, 0, -1, 0 };
				nq.push_back((i * m + j) * 4 + (t + 3) % 4);
				for(int d = 0; d < 4; ++ d) {
					int yy = i + dy[d], xx = j + dx[d];
					if(yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
					if(~door[i][j] >> ((d + t) % 4) & 1) continue;
					if(~door[yy][xx] >> ((d + t + 2) % 4) & 1) continue;
					nq.push_back((yy * m + xx) * 4 + t);
				}
			}
			++ dist;
		}
		if(ans == INF)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	return 0;
}