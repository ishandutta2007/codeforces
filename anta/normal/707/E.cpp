#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int m; int k;
	mt19937 re;
	while(~scanf("%d%d%d", &n, &m, &k)) {
		typedef pair<int, long long> Edge;
		vector<vector<Edge>> hori(m + 1, vector<Edge>(n, Edge(k, 0)));
		vector<vector<Edge>> vert(n + 1, vector<Edge>(m, Edge(k, 0)));
		vector<pair<pair<int, int>, long long>> tail(k);
		rep(i, k) {
			int len;
			scanf("%d", &len);
			int py = -1, px = -1;
			long long sum = 0;
			rep(j, len) {
				int y; int x; int w;
				scanf("%d%d%d", &y, &x, &w), -- y, -- x;
				if(py == y)
					hori[max(x, px)][y] = Edge(i, (px < x ? -1 : 1) * sum);
				if(px == x)
					vert[max(y, py)][x] = Edge(i, (py < y ? -1 : 1) * sum);
				sum += w;
				py = y, px = x;
			}
			tail[i] = { {py, px}, sum };
		}
		int q;
		scanf("%d", &q);
		vector<bool> state(k + 1);
		rep(i, k)
			state[i] = true;
		vector<long long> sums(k + 1);
		for(int ii = 0; ii < q; ++ ii) {
			char ty[10];
			scanf("%s", ty);
			if(*ty == 'S') {
				int i;
				scanf("%d", &i), -- i;
				state[i] = !state[i];
			} else if(*ty == 'A') {
				int y1; int x1; int y2; int x2;
				scanf("%d%d%d%d", &y1, &x1, &y2, &x2), -- y1, -- x1;

				sums.assign(k + 1, 0LL);
				reu(y, y1, y2) {
					sums[hori[x1][y].first] += hori[x1][y].second;
					sums[hori[x2][y].first] -= hori[x2][y].second;
				}
				reu(x, x1, x2) {
					sums[vert[y1][x].first] += vert[y1][x].second;
					sums[vert[y2][x].first] -= vert[y2][x].second;
				}

				long long ans = 0;
				rep(i, k) if(state[i]) {
					int y, x;
					tie(y, x) = tail[i].first;
					if(y1 <= y && y < y2 && x1 <= x && x < x2) {
						sums[i] += tail[i].second;
					}
					ans += abs(sums[i]);
				}
				printf("%lld\n", ans);
			} else abort();
		}
	}
	return 0;
}