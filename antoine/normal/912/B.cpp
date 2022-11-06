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

using namespace std;

const int mod = (int)1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, k;
	cin >> n >> k;
	if (k != 1)
		for (int i = 0; (1ll << i) <= n; ++i)
			n |= (1ll << i);
	cout << n;
	return 0;
}