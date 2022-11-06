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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	int xl = 0;
	while (count(a[xl].begin(), a[xl].end(), 'B') == 0)
		++xl;
	int xr = n - 1;
	while (count(a[xr].begin(), a[xr].end(), 'B') == 0)
		--xr;
	
	int yl = 0, yr = m - 1;
	while (a[xl][yl] == 'W') ++yl;
	while (a[xl][yr] == 'W') --yr;
	cout << (xl + xr) / 2 + 1 << ' ' << (yl + yr) / 2 + 1 << '\n';
	return 0;
}