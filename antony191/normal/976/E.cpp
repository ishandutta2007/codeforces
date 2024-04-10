#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, a, b;
	cin >> n >> a >> b;
	b = min(n, b);
	vector<pair<ll, ll>> c(n);
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		ll tmp;
		cin >> c[i].second >> tmp;
		sum += tmp;
		c[i].first = c[i].second - tmp;
	}
	if (b == 0)
		return cout << sum, 0;
	sort(all(c));
	reverse(all(c));
	int r, i;
	for (i = 0; i < b && c[i].first > 0; ++i) {
		sum += c[i].first;
	}
	ll mx = sum;
	r = i;
	bool t = r == b;
	for (i = 0; i < n; ++i) {
		ll tmp = c[i].second * 1ll * (1 << a) + c[i].first - c[i].second;
		if (i < r) {
			mx = max(mx, sum + tmp - c[i].first);
		}
		else
		{
			mx = max(mx, sum + tmp - (t ? c[r - 1].first : 0));
		}
	}
	cout << mx;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}