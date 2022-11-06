#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;

long long c[32];

long long f(long long L) {
	if (L == 0)
		return 0;
	long long i = 1;
	while ((1ll << i) <= L)
		++i;
	return min(c[min(i, 31ll)], c[i - 1] + f(L ^ (1ll << (i-1))));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	cin >> n;
	long long L;
	cin >> L;

	for (long long i = 0; i < 32; ++i) {
		if (i < n) {
			cin >> c[i];
			if (i)
				c[i] = min(c[i], c[i - 1] << 1);
		}
		else
			c[i] = c[i - 1] << 1;
	}

	for (long long i = 30; i >= 0; --i)
		c[i] = min(c[i], c[i + 1]);

	cout << f(L);

	return 0;
}