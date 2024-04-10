#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <unordered_map>

int smf[1001];

long long f(long long d, long long n) {
	if (d <= 1 || (d <= 1000 && smf[d]))
		return 0;
	long long result = 0;
	for (n /= d; n ; n /= d) {
		result += n;
		break;
	}
	return result;
}

int main() {
	for (int i = 2; i < 1001; ++i) {
		if (!smf[i]) {
			for (long long j = i*i; j < 1001; j += i)
				smf[j] = i;
		}
	}
	long long l, r;
	std::cin >> l >> r;
	long long max = f(l, r) - f(l, l - 1);
	int ans = l;
	for (int i = 2; i*i <= l || i*i <= r; ++i) {
		long long count = f(i, r) - f(i, l-1);
		if (count > max) {
			max = count;
			ans = i;
		}
	}

	std::cout << ans;
	return 0;
}