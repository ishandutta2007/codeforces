#include <iostream>

#define MAXN 501

int n, k;
int m;
int g[MAXN];

void query(int x) {
	std::cout << "? ";
	for(int i = 0; i <= k; i++)
		if(x != i)
			std::cout << i+1 << " ";
	std::cout << std::endl;
	std::cin >> g[x] >> g[x];
	//g[x] = m + (x < m);
}

int main() {
	std::cin >> n >> k;
	//std::cin >> m;
	
	int max = -1;
	int ans = 0;
	for(int i = 0; i <= k; i++) {
		query(i);
		if(max == g[i]) {
			ans++;
		} else if(max < g[i]) {
			max = g[i];
			ans = 1;
		}
	}
	
	std::cout << "! ";
	std::cout << ans << std::endl;
	
	return 0;
}