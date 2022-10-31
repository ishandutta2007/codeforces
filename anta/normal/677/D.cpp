#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int n; int m; int p;
	while(~scanf("%d%d%d", &n, &m, &p)) {
		vector<vector<int> > a(n, vector<int>(m));
		for(int i = 0; i < n; ++ i) for(int j = 0; j < m; ++ j)
			scanf("%d", &a[i][j]), -- a[i][j];
		vector<vpii> poses(p);
		rep(i, n) rep(j, m)
			poses[a[i][j]].emplace_back(i, j);
		vector<vpii> dist(n), ndist(n);
		rep(y, n) {
			dist[y].reserve(m);
			ndist[y].reserve(m);
		}
		for(auto p : poses[0])
			ndist[p.first].emplace_back(p.second, p.first + p.second);
		for(int k = 1; k < p; ++ k) {
			dist.swap(ndist);
			rep(y, n)
				ndist[y].clear();
			rep(i, poses[k].size()) {
				int y, x; tie(y, x) = poses[k][i];
				int d = INF;
				rep(py, n) {
					const vpii &v = dist[py];
					if(v.empty()) continue;
					auto it = lower_bound(v.begin(), v.end(), make_pair(x, -1));
					if(it != v.end())
						amin(d, it->second + abs(y - py) + abs(x - it->first));
					if(it != v.begin()) {
						-- it;
						amin(d, it->second + abs(y - py) + abs(x - it->first));
					}
				}
				ndist[y].push_back(make_pair(x, d));
			}
			rep(y, n) {
				vpii &v = ndist[y];
				if(v.size() <= 1) continue;
				for(int i = 0; i < (int)v.size() - 1; ++ i)
					amin(v[i + 1].second, v[i].second + (v[i + 1].first - v[i].first));
				for(int i = (int)v.size() - 2; i >= 0; -- i)
					amin(v[i].second, v[i + 1].second + (v[i + 1].first - v[i].first));
			}
		}
		int ans = INF;
		rep(y, n)
			for(auto p : ndist[y])
				amin(ans, p.second);
		printf("%d\n", ans);
	}
	return 0;
}