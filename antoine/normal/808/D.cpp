#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <set>

long long a[100000];
long long S;
long long n;

bool g() {
	std::set<long long> set;
	long long s = (S << 1);

	for (int i = 0; i < n; ++i) {
		set.insert(a[i]);
		s -= a[i];
		if (s == S || set.count(S - s))
			return true;
	}
	return false;
}


bool f() {
	std::cin >> n;
	for (long long i = 0; i < n; ++i) {
		std::cin >> a[i];
		S += a[i];
	}

	if (S & 1)
		return false;
	S >>= 1;
	if (g())
		return true;
	std::reverse(a, a + n);
	return g();
}

int main() {
	std::cout << (f() ? "YES" : "NO");
	return 0;
}