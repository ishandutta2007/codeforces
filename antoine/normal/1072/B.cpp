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

bool f(const vector<int> &a, const vector<int> &b, vector<int> &t) {
	const int n = t.size();
	for (int i = n - 2; i >= 0; --i) {
		for (int &x = t[i] = 0; x < 4; ++x)
			if ((x | t[i + 1]) == a[i] && (x & t[i + 1]) == b[i])
				break;
		if (t[i] == 4)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n - 1), b(n - 1);
	for (int i = 0; i < n - 1; ++i)
		cin >> a[i];
	for (int i = 0; i < n - 1; ++i)
		cin >> b[i];
	vector<int> t(n);
	for (int &i = t.back() = 0; i < 4; ++i)
		if (f(a, b, t)) {
			cout << "YES\n";
			for (auto &&x : t)
				cout << x << ' ';
			return 0;
		}
	cout << "NO";
	return 0;
}