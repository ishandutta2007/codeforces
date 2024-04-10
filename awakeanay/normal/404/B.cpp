#include <iostream>

#define MOD 1000000007
#define int long long

double a;

std::pair<double, double> conv(double l) {
	while(l > 4*a)
		l -= 4*a;
	if(l < a)
		return {l, 0};
	if(l < 2*a)
		return {a, l-a};
	if(l < 3*a)
		return {a-(l-2*a), a};
	return {0, a-(l-3*a)};
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	double d;
	std::cin >> a >> d;
	
	int n;
	std::cin >> n;
	
	double a2 = 2*a;
	double a3 = 3*a;
	
	double l = 0;
	for(int i = 0; i < n; i++) {
		l += d;
		while(l > 32*a)
			l -= 32*a;
		while(l > 4*a)
			l -= 4*a;
		if(l < a)
			std::cout << l << " " << 0;
		else if(l < 2*a)
			std::cout << a << " " << l-a;
		else if(l < 3*a)
			std::cout << a-(l-2*a) << " " << a;
		else std::cout << 0 << " " << a-(l-3*a);
			std::cout << std::endl;
	}
}