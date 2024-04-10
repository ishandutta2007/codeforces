#include <iostream>
#include <algorithm>
#include <vector>

#define int long long

signed main() {
	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<int> rows[m];
	std::vector<int> cols[n];

	for(int i = 0; i < n; i++) {
		cols[i].push_back(-1);
		cols[i].push_back(m);
	}
	for(int i = 0; i < m; i++) {
		rows[i].push_back(-1);
		rows[i].push_back(n);
	}

	for(int i = 0; i < k; i++) {
		int x, y;
		std::cin >> x >> y; x--; y--;
		cols[x].push_back(y);
		rows[y].push_back(x);
	}

	for(int i = 0; i < n; i++)
		std::sort(cols[i].begin(), cols[i].end());
	for(int i = 0; i < m; i++)
		std::sort(rows[i].begin(), rows[i].end());

	int l = 0, u = 0, r = n-1, d = m-1;

	int x = 0, y = -1;
	int dir = 1;
	int done = 0;

	while(true) {
		if(dir == 1) {
			int ny = (*std::upper_bound(cols[x].begin(), cols[x].end(), y))-1;
			//std::cout << x << " here " << ny << std::endl;
			ny = std::min(ny, d);
			done += ny-y;
			d = ny;
			l = std::max(x+1, l);
			if(ny == y)
				break;
			y = ny;
		}
		else if(dir == 2) {
			int nx = (*std::upper_bound(rows[y].begin(), rows[y].end(), x))-1;
			nx = std::min(nx, r);
			done += nx-x;
			r = nx;
			d = std::min(y-1, d);
			if(nx == x)
				break;
			x = nx;
		}
		else if(dir == 3) {
			int ny = (*(std::upper_bound(cols[x].begin(), cols[x].end(), y)-1))+1;
			//std::cout << *(std::upper_bound(cols[x].begin(), cols[x].end(), y)-2) << std::endl;
			ny = std::max(ny, u);
			done += y-ny;
			u = ny;
			r = std::min(x-1, r);
			if(ny == y)
				break;
			y = ny;
		}
		else if(dir == 4) {
			int nx = (*(std::upper_bound(rows[y].begin(), rows[y].end(), x)-1))+1;
			//std::cout << *(std::upper_bound(rows[y].begin(), rows[y].end(), x)-1) << std::endl;
			nx = std::max(nx, l);
			done += x-nx;
			l = nx;
			u = std::max(y+1, u);
			if(nx == x)
				break;
			x = nx;
		}
		//std::cout << x << " " << y << " " << d << std::endl;
		dir = (dir%4)+1;
	}

	if(done + k == n*m)
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl;

	return 0;
}