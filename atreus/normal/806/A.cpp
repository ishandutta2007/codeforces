#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

int main () {
	int tc;
	cin >> tc;
	while (tc --) {
		ll x, y, p, q;
		cin >> x >> y >> p >> q;
		ll l = 0, r = inf;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			ll pp = mid * p, qq = mid * q;
			if (pp >= x and qq >= y and pp - x <= qq - y)
				r = mid;
			else
				l = mid;
		}
		if (r == inf)
			cout << -1 << endl;
		else {
			p = r * p, q = r * q;
			cout << q - y << endl;
		}
	}
}