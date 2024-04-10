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
#undef NDEBUG
#include <assert.h>
#include <random>

using namespace std;
typedef long long ll;


ll _pow(ll x, ll y) {
	ll res = 1;
	while (y--)
		res *= x;
	return res;
}

void B() {
	int x, y;
	cin >> x >> y;
	if (x == y)
		cout << '=';
	else if (x == 1)
		cout << '<';
	else if (y == 1)
		cout << '>';
	else if (max(x, y) <= 5) {
		ll diff = _pow(x, y) - _pow(y, x);
		cout << (diff < 0 ? '<' : diff ? '>' : '=');
	} else
		cout << (x < y ? '>' : '<');
}

void D() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	if (!a[0]) {
		cout << 1;
		return;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	B();

	return 0;
}