#include <iostream>
#include <iomanip>

#define int long long

signed main() {
	int n, p;
	std::cin >> n >> p;

	double pro[n];
	for(int i = 0; i < n; i++) {
		int l, r;
		std::cin >> l >> r;
		double good = r/p - (l-1)/p;
		double num = r-l+1;
		pro[i] = good/num;
	}
	
	double ans = 0;
	for(int i = 0; i < n; i++) {
		ans += 2*(pro[i] + pro[(i+1)%n] - pro[i]*pro[(i+1)%n]);
	}
	
	std::cout << std::setprecision(7) << ans*1000 << std::endl;
	
	return 0;
}