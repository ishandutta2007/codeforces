#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

long long n, k;

bool f() {
	cin >> n >> k;
	
	k = min(k, n + 5);

	for (long long i = min(k, (long long)1e5); i >= 2; --i)
		if (n%i != i - 1)
			return false;

	for(long long i = max(2ll, k - (long long)1e5); i <= k; ++i)
		if (n%i != i - 1)
			return false;

	if (k <= 1e5)
		return true;
	if (k >= n)
		return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << (f() ? "Yes" : "No");

	return 0;
}