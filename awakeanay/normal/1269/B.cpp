#include <iostream>
#include <algorithm>

#define int long long

int m;

int safe(int x) {
	if(x < 0) {
		x = -x;
		x = x%m;
		x = -x;
		while(x < 0)
			x += m;
		return x;
	} else {
		return x%m;
	}
}

signed main() {
	int n;
	std::cin >> n >> m;

	int a[n], b[n];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];

	for(int i = 0; i < n; i++)
		std::cin >> b[i];

	std::sort(a, a+n);
	std::sort(b, b+n);

	int x = 100000000000;

	for(int i = 0; i < n; i++) {
		int fix = (b[i]-a[0]);
		fix = safe(fix);

		bool poss = true;
		for(int j = 0; j < n; j++) {
			if(safe(b[(i+j)%n] - a[j]) != fix)
				poss = false;
		}
		if(poss) {
			x = std::min(x, fix);
		}
	}

	std::cout << x << std::endl;

	return 0;
}