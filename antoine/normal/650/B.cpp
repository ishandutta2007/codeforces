#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

int n, a, b, T;
int t[500000];

int f() {
	T -= t[0];
	if (T < 0)
		return 0;
	if (n == 1)
		return 1;

	int ans = 1;

	int time = T;
	int i = 1;
	for (; i < n; ++i) {
		time -= a + t[i];
		if (time < 0)
			break;
	}
	ans = std::max(ans, i);

	time = T;
	for (i = n - 1; i > 0; --i) {
		time -= a + t[i];
		if (time < 0)
			break;
	}

	
	ans = std::max(ans, n - i);

	if (ans == n || ans <= 2 || n <= 2)
		return ans;
	time = T - a - t[n - 1];
	i = n - 1;
	int count = 2;
	while (time >= 0) {
		++count;
		time -= t[--i] + a;
	}
	--count;
	time += t[i++] + a;
	for (int j = 1;; ++j) {
		time -= 2 * a + t[j];
		++count;
		while (i <= n - 1 && time < 0) {
			time += a + t[i++];
			--count;
		}
		if (i == n)
			break;
		ans = std::max(ans, count);
	}

	time = T - 2*a - t[n - 1];
	if (time <= 0)
		return ans;
	
	i = n - 1;
	count = 2;
	while (time >= 0) {
		++count;
		time -= t[--i] + 2*a;
	}
	--count;
	time += t[i++] + 2*a;
	for (int j = 1;; ++j) {
		time -= a + t[j];
		++count;
		while (i <= n - 1 && time < 0) {
			time += 2*a + t[i++];
			--count;
		}
		if (i == n)
			break;
		ans = std::max(ans, count);
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::string str;
	std::cin >> n >> a >> b >> T >> str;
	for (int i = n - 1; i >= 0; --i)
		t[i] = (str[i] == 'h' ? 1 : (1 + b));
	std::cout << f();
	return 0;
}