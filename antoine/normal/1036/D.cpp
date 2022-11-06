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

vector<int> getArr() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	return v;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	auto a = getArr();
	auto b = getArr();

	ll diff = 0, res = 0;
	while (!a.empty() || !b.empty()) {
		if (b.empty() || (!a.empty() && diff < 0)) {
			diff += a.back();
			a.pop_back();
		}
		else {
			diff -= b.back();
			b.pop_back();
		}
		res += !diff;
	}
	cout << (diff ? -1 : res) << '\n';
	return 0;
}