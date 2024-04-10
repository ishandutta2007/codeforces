#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int n, w, h, x[100000], y[100000];
vector<pair<int, int>> hor[199999], ver[199999];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> w >> h;
	for(int i = 0; i < n; i++) {
		int g, p, t; cin >> g >> p >> t;
		if(g == 1) hor[t - p + 99999].push_back({p, i});
		else ver[t - p + 99999].push_back({p, i});
	}
	for(int i = 0; i < 199999; i++)
		if(!ver[i].empty()) {
			if(!hor[i].empty()) {
				sort(hor[i].begin(), hor[i].end());
				sort(ver[i].begin(), ver[i].end());
				int sz1 = ver[i].size(), sz2 = hor[i].size();
				vector<int> vx(sz1 + sz2), vy(sz1 + sz2);
				for(int j = 0; j < sz2; j++) vx[j] = hor[i][j].fi, vy[j] = h;
				for(int j = sz1 - 1; j >= 0; j--) vx[sz1 - j - 1 + sz2] = w, vy[sz1 - j - 1 + sz2] = ver[i][j].fi;
				int pt = 0;
				for(int j = sz1 - 1; j >= 0; j--) {
					x[ver[i][j].se] = vx[pt];
					y[ver[i][j].se] = vy[pt];
					pt++;
				}
				for(int j = 0; j < sz2; j++) {
					x[hor[i][j].se] = vx[pt];
					y[hor[i][j].se] = vy[pt];
					pt++;
				}
			} else
				for(pair<int, int> z : ver[i]) {
					x[z.se] = w;
					y[z.se] = z.fi;
				}
		} else
			for(pair<int, int> z : hor[i]) {
				x[z.se] = z.fi;
				y[z.se] = h;
			}
	for(int i = 0; i < n; i++) cout << x[i] << ' ' << y[i] << '\n';
}