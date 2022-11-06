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
#include <assert.h>
#include <numeric>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, l;
	cin >> n >> k >> l;
	vector<int> a(n*k);
	for (int i = 0; i < a.size(); ++i)
		cin >> a[i];
	sort(a.begin(), a.end());

	ll ans = 0;
	int count = 0;
	for (int i = a.size() - 1; i >= 0; --i) {
		if (++count >= k && a[i] - a[0] <= l && n) {
			ans += a[i];
			count -= k;
			n--;
		}
	}
	cout << (n ? 0 : ans);
	return 0;
}