#include <iostream>
#include <algorithm>

#define int long long

signed main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	
	int a[n];
	int b[m];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	for(int i = 0; i < m; i++)
		std::cin >> b[i];
	
	bool poss = true;
	if(m >= n) {
		std::sort(a, a+n);
		std::sort(b, b+m);
		
		bool cur = true;
		for(int i = 0; i < n; i++) {
			cur &= a[i] <= b[i+m-n];
		}
		
		if(cur)
			poss = false;
	}
	
	if(poss)
		std::cout << "YES";
	else
		std::cout << "NO";
	
	return 0;
}