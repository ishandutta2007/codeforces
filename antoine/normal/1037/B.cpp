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
	cin.tie(0), cout.tie(0);

	ll n, s;
	cin >> n >> s;

	priority_queue<ll> pq1;
	priority_queue<ll, vector<ll>, greater<ll>> pq2;

	for (ll i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		if (x > s)
			pq2.push(x);
		else
			pq1.push(x);
	}

	ll ans = 0;
	while (pq1.size() > n / 2) {
		ans += abs(s - pq1.top());
		pq1.pop();
	}
	while (pq2.size() > n / 2) {
		ans += abs(s - pq2.top());
		pq2.pop();
	}

	cout << ans << endl;
	return 0;
}