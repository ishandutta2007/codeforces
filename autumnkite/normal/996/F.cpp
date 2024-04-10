#include <bits/stdc++.h>

const int N = 18;

int n, r;
int a[1 << N];
long long sum;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);
	
	std::cin >> n >> r;
	for (int i = 0; i < (1 << n); ++i) {
		std::cin >> a[i];
		sum += a[i];
	}
	std::cout << 1.0 * sum / (1 << n) << "\n";
	while (r--) {
		int x, v;
		std::cin >> x >> v;
		sum -= a[x];
		a[x] = v;
		sum += a[x];
		std::cout << 1.0 * sum / (1 << n) << "\n";
	}
}