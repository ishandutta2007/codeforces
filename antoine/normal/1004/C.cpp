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
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> cntR(n);
	set<int> s;
	for (int i = n - 1; i >= 0; --i) {
		cntR[i] = s.size();
		s.insert(a[i]);
	}


	ll res = 0;
	s.clear();
	for (int i = 0; i < n; ++i) {
		if (s.count(a[i]))
			continue;
		s.insert(a[i]);
		res += cntR[i];
	}
	cout << res;
	return 0;
}