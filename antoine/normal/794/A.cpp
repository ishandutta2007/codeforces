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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(11);

	ll a, b, c, n, res = 0;
	cin >> a >> b >> c >> n;
	while(n--) {
		ll x;
		cin >> x;
		res += x > b && x < c;
	}
	cout << res;
	return 0;
}