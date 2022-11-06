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
#include <stack>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k, k2;
	cin >> n >> k >> k2;
	k += k2;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		int b; 
		cin >> b;
		a[i] = abs(a[i] - b);
	}
	sort(a.begin(), a.end());
	while (a.size() && k) {
		if (!a.back()) {
			a.pop_back();
		}
		else {
			a.back() = abs(a.back() - 1);
			k--;
			sort(a.begin(), a.end());
		}
	}
	ll res = k & 1;
	for (auto &&x : a) {
		res += 1ll * x *x;
	}
	cout << res;
	return 0;
}