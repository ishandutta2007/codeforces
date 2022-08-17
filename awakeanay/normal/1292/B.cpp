#include <iostream>

#define INF 20000000000000000
#define int long long
#define MAX 100
#define x first
#define y second

int abso(int x) {
	if(x >= 0)
		return x;
	return -x;
}

signed main() {
	int ax, ay, bx, by;
	std::pair<int, int> data[MAX];
	std::cin >> data[0].x >> data[0].y >> ax >> ay >> bx >> by;
	
	int xs, ys, t;
	std::cin >> xs >> ys >> t;
	
	int m = 1;
	for(int i = 1; i < MAX; i++) {
		data[i].x = ax*data[i-1].x + bx;
		data[i].y = ay*data[i-1].y + by;
		m++;
		//std::cout << data[i].x << " " << data[i].y << std::endl;
		if(data[i].x > INF || data[i].y > INF)
			break;
	}
	
	//std::cout << m << std::endl;
	
	int ans = 0;
	for(int i = 0; i < m; i++) {
		for(int j = i; j < m; j++) {
			for(int k = i; k <= j; k++) {
				int up = data[j].x + data[j].y - data[k].x - data[k].y;
				int down = data[k].x + data[k].y - data[i].x - data[i].y;
				int dist = abso(data[k].x - xs) + abso(data[k].y - ys);
				//std::cout << up << " " << down << " " << dist << " " << i << " " << k << " " << j << std::endl;
				if(up + down + dist + std::min(up, down) <= t) {
					//std::cout << data[k].x << " " << data[k].y << " " << dist << " " << abso(data[k].x - xs) << " " << k << " " << j << std::endl;
					ans = std::max(ans, j-i+1);
				}
			}
		}
	}
	
	std::cout << ans << std::endl;
}