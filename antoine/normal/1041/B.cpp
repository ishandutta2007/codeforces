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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll a, b, x, y;
	cin >> a >> b >> x >> y;

	const ll g = gcd(x, y);
	x /= g;
	y /= g;


	ll ans = min(a / x, b / y);
	cout << ans << '\n';

	return 0;
}