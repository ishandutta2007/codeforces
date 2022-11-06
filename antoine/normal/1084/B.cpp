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

	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;

	const ll sum = accumulate(a.begin(), a.end(), 0LL);
	const ll mn = *min_element(a.begin(), a.end());

	s -= sum - mn * n;
	s = max(0LL, s);

	ll ans = mn - (s + n-1)/n;
	cout << max(-1LL, ans);
	return 0;
}