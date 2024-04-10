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
#include <array>

using namespace std;

const long long mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> f(n+1);
	for (int i = 1; i <= n; ++i)
		cin >> f[i];
	for (int i = 1; i <= n; ++i) {
		int x = i;
		x = f[x];
		x = f[x];
		x = f[x];
		if (x == i) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}