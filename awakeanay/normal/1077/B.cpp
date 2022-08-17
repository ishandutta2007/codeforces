#include <iostream>
using namespace std;

#define int long long

signed main() {
	int n;
	std::cin >> n;
	
	int a[n+2];
	a[0] = a[n+1] = 0;
	for(int i = 1; i <= n; i++)
		std::cin >> a[i];
		
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i-1] == 1 && a[i+1] == 1 && a[i] == 0) {
			ans++;
			a[i+1] = 0;
		}
	}
	
	std::cout << ans << std::endl;
}