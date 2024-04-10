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

int n;
int a[100];

int f() {
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];
	return round((double)sum / (double)n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	while (f() < 5) {
		ans++;
		assert(a[0] < 5);
		a[0] = 5;
		sort(a, a + n);
	}
	cout << ans;

	return 0;
}