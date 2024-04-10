#include <iostream>
#include <algorithm>

#define int long long

signed main() {
	int n, k;
	std::cin >> n >> k;
	
	int a[n];
	
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
		
	std::sort(a, a+n);
	
	int l = 0;
	int cur = 0;
	int max = 1;
	int id = a[0];
	for(int i = 1; i < n; i++) {
		cur += (i-l)*(a[i]-a[i-1]);
		
		while(cur > k) {
			cur -= a[i]-a[l];
			l++;
		}
		
		if(i-l+1 > max) {
			max = i-l+1;
			id = a[i];
		}
	}
	
	std::cout << max << " " << id << std::endl;
}