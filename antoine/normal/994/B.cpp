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

// B

struct MS {
	ll sum = 0;
	multiset<int> ms;
	void insert(int x) {
		sum += x;
		ms.insert(x);
	}
	void remOne() {
		auto it = ms.begin();
		sum -= *it;
		ms.erase(it);
	}
	int size() {
		return ms.size();
	}
};

struct Knight {
	int i, p, c;
	bool operator<(const Knight &other) const {
		return p < other.p;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<Knight> v(n);
	vector<ll> ans(n);
	for (int i = 0; i < n; ++i) {
		v[i].i = i;
		cin >> v[i].p;
	}
	for (int i = 0; i < n; ++i)
		cin >> v[i].c;
	sort(v.begin(), v.end());
	
	MS ms;
	for (int i = 0, j = 0; j < n; ++j) {
		while (v[i].p < v[j].p)
			ms.insert(v[i++].c);
		while (ms.size() > k)
			ms.remOne();
		ans[v[j].i] = ms.sum + v[j].c;
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	return 0;
}