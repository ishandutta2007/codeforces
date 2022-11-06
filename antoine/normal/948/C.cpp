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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(0);

	int n;
	cin >> n;
	vector<ll> v(n), t(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];

	ll offset = 0;
	priority_queue<ll, vector <ll>, greater<ll>> pq;
	for (int i = 0; i < n; ++i) {
		pq.push(v[i] + offset);
		ll ans = 0;
		while (!pq.empty() && pq.top() <= offset + t[i]) {
			ans += pq.top() - offset;
			pq.pop();
		}
		ans += t[i] * pq.size();
		offset += t[i];
		cout << ans << ' ';
	}
	return 0;
}