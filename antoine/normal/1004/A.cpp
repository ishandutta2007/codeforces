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

ll n, d;
ll a[101];

bool f(ll x) {
	for (int i = 0; i < n; ++i)
		if (abs(a[i] - x) < d)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	cin >> n >> d;
	set<int> candidates;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		candidates.insert(a[i] - d);
		candidates.insert(a[i] + d);
	}
	ll res = 0;
	for (auto &&x : candidates)
		if (f(x)) {
			// cerr << "ok: " << x << endl;
			res++;
		}
	cout << res;
	return 0;
}