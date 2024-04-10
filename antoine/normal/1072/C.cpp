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

ll f(ll x) {

	ll lo = 0, hi = (ll) 1e8;
	while (lo < hi) {
		ll mid = (lo + hi + 1) / 2;
		if (mid * (mid + 1) / 2 <= x)
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}

void p(const vector<ll> &v) {
	cout << v.size() << '\n';
	for(auto &&x : v)
		cout << x << ' ';
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b;
	cin >> a >> b;


	ll n = f(a+b);

	vector<ll> u;
	ll sumU = 0;
	while(n >= 1 && sumU + n <= a) {
		u.push_back(n);
		sumU += n--;
	}
	if(n >= 1 && sumU < a) {
		assert(a - sumU <= n);
		u.push_back(a - sumU);
	}
	vector<ll> v;
	for(; n >= 1; n--)
	if(u.empty() || n != u.back())
		v.push_back(n);

	p(u);
	p(v);
	return 0;
}