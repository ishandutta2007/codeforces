#include <iostream>
#include <algorithm>

#define int long long
#define INF 1000000000

struct p {
	int x, y, z;
	int id;
};

inline bool operator<(p a, p b) {
	if(a.x < b.x)
		return true;

	if(a.x == b.x && a.y < b.y)
		return true;

	if(a.x == b.x && a.y == b.y && a.z < b.z)
		return true;

	return false;
}

signed main() {
	int n;
	std::cin >> n;

	p ps[n];
	for(int i = 0; i < n; i++) {
		std::cin >> ps[i].x >> ps[i].y >> ps[i].z;
		ps[i].id = i+1;
	}

	std::sort(ps, ps+n);

	bool mark[n+1];
	for(int i = 0; i < n+1; i++)
		mark[i] = false;

	int lid = -1, lx = INF, ly = INF;
	for(int i = 0; i < n; i++) {
		if(mark[ps[i].id])
			continue;

		if(lx == ps[i].x && ly == ps[i].y) {
			std::cout << lid << " " << ps[i].id << std::endl;
			mark[lid] = mark[ps[i].id] = true;
			lid = -1; lx = INF; ly = INF;
		}
		else {
			lid = ps[i].id;
			lx = ps[i].x;
			ly = ps[i].y;
		}
	}

	lid = -1; lx = INF;
	for(int i = 0; i < n; i++) {
		if(mark[ps[i].id])
			continue;

		if(lx == ps[i].x) {
			std::cout << lid << " " << ps[i].id << std::endl;
			mark[lid] = mark[ps[i].id] = true;
			lid = -1; lx = INF;
		}
		else {
			lid = ps[i].id;
			lx = ps[i].x;
		}
	}

	lid = -1;
	for(int i = 0; i < n; i++) {
		if(mark[ps[i].id])
			continue;

		if(lid > -1) {
			std::cout << lid << " " << ps[i].id << std::endl;
			mark[lid] = mark[ps[i].id] = true;
			lid = -1; lx = INF;
		}
		else {
			lid = ps[i].id;
			lx = ps[i].x;
		}
	}

	return 0;
}