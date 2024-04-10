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

int f(int &X) {
	ll m = 1;
	int count = 0;
	while (m <= X) {
		m = m << 1 | 1;
		++count;
	}
	X -= m >> 1;
	return count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int X, d;
	cin >> X >> d;

	vector<ll> ans;
	for (ll count, offset = 1; count = f(X); offset += 4e9) {
		while (count--)
			ans.push_back(offset);
	}
	cout << ans.size() << '\n';
	for (auto &&x : ans)
		cout << x << ' ';
	return 0;
}