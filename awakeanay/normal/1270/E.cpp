#include <iostream>
#include <vector>

#define int long long
#define x first
#define y second

signed main() {
	int n;
	std::cin >> n;
	
	std::vector<std::pair<int, int> > point(n);
	for(int i = 0; i < n; i++)
		std::cin >> point[i].x >> point[i].y;
	
	while(true) {
		std::vector<int> type[2];
		for(int i = 0; i < n; i++) {
			type[abs(point[i].x + point[i].y)%2].push_back(i);
			int nx, ny;
			nx = (point[i].x + point[i].y + abs(point[i].x + point[i].y)%2)/2;
			ny = (point[i].x - point[i].y + abs(point[i].x + point[i].y)%2)/2;
			point[i].x = nx;
			point[i].y = ny;
		}
		if(type[0].size()*type[1].size() > 0) {
			std::cout << type[0].size() << std::endl;
			for(int j : type[0])
				std::cout << j+1 << " ";
			break;
		}
	}
	
	std::cout << std::endl;
	
	return 0;
}