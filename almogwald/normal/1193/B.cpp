#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#define forr(i,a,b,c) for(int i = a;i < b;i+=c)
#define fort(i,a,b) forr(i,a,b,1)
#define fori(i,a) fort(i,0,a)
#define forn(i,b) fort(i,1,b)
#define forrb(i,a,b,c) for(int i = b-1;i >= a;i-=c)
#define fortb(i,a,b) forrb(i,a,b,1)
#define forib(i,a) fortb(i,0,a)
#define fornb(i,b) fortb(i,1,b)
#define into(i) cin >> i
#define con continue;
#define br  break;
#define co cout <<
#define ell  << '\n';
#define veci vector<int>
using namespace std;
#define logn 17
#define point pair<int,int>
typedef long long lol;
#define veci vector<lol>
map<pair<point, point>, lol> mapit;
void addd(int x, int y, int v) {
	fori(i, logn) {
		fori(j, logn) {
			int nx = x & (-(1 << i));
			int ny = y & (-(1 << j));
			pair<point, point> cur = { {nx,ny} ,{i,j} };
			if (mapit.find(cur) == mapit.end()) {
				mapit[cur] = 0;
			}
			mapit[cur] += v;
		}
	}
}
lol summ(int x1, int x2, int y) {
	lol ans = 0;
	int i = 0;
	while (x1 <= x2) {
		while (((1 << i)&x1 )== 0) {
			i++;
		}
		while (x1 + (1 << i) -1 > x2) {
			i--;
		}
		int j = 0;
		int yy = y;
		while (yy < (1 << logn)) {
			while ((yy & (1 << j)) == 0) {
				j++;
			}
			pair<point, point> cur = { { x1,yy } ,{ i,j } };
			if (mapit.find(cur) != mapit.end()) {
				ans += mapit[cur];
			}
			yy += 1 << j;
		}
		x1 += 1 << i;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	veci p(n);
	vector<veci> cons(n);
	forn(i, n) {
		into(p[i]);
		p[i]--;
		cons[p[i]].push_back(i);
	}
	veci s(n, 1);
	fornb(i, n) {
		s[p[i]] += s[i];
	}
	veci ord;
	veci dfs;
	dfs.push_back(0);
	while (dfs.size()) {
		int cur = dfs.back();
		dfs.pop_back();
		forib(i, cons[cur].size()) {
			dfs.push_back(cons[cur][i]);
		}
		ord.push_back(cur);
	}
	veci d(n,-1);
	veci v(n);
	fori(i, m) {
		int x;
		cin >> x;
		x--;
		cin >> d[x] >> v[x];
	}
	veci y(n);
	vector<map<int,lol>> mapit;
	forib(i, n) {
		int cur = ord[i];
		if (cons[cur].size() == 0) {
			y[cur] = mapit.size();
			map<int, lol> mop;
			if (d[cur] != -1) {
				mop[d[cur]] = v[cur];
			}
			mapit.push_back(mop);
			continue;
		}
		int ss = 0;
		fori(j, cons[cur].size()) {
			if (s[cons[cur][j]] > ss) {
				ss = s[cons[cur][j]];
				y[cur] = y[cons[cur][j]];
			}
		}
		fori(j, cons[cur].size()) {
			if (y[cons[cur][j]] != y[cur]) {
				int yy = y[cons[cur][j]];
				for (auto it = mapit[yy].begin(); it != mapit[yy].end(); it++) {
					int x = it->first;
					lol z= it->second;
					if (mapit[y[cur]].find(x) == mapit[y[cur]].end()) {
						mapit[y[cur]][x] = 0;
					}
					mapit[y[cur]][x] += z;
				}
			}
		}
		if (d[cur] != -1) {
			int z = v[cur];
			for (auto it = mapit[y[cur]].upper_bound(d[cur]); it != mapit[y[cur]].end();) {
				if (it->second > z) {
					mapit[y[cur]][it->first] -= z;
					break;
				}
				auto itt = it;
				it++;
				z -= itt->second;
				mapit[y[cur]].erase(itt);
			}
			if (mapit[y[cur]].find(d[cur]) == mapit[y[cur]].end()) {
				mapit[y[cur]][d[cur]] = 0;
			}
			mapit[y[cur]][d[cur]] += v[cur];
		}
	}
	lol ans = 0;
	for (auto it = mapit[y[0]].begin(); it != mapit[y[0]].end(); it++) {
		ans += it->second;
	}
	co ans ell
	return 0;
}