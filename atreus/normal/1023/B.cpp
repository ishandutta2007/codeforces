#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 1e5 + 5;
const int maxm = 2e3 + 100;
const int mod = 1e9 + 7;
const ll inf = (1ll << 62);
const int block = 317;

ull base = 31;

int main () {
	ios_base::sync_with_stdio (false);
	ll n, k;
	cin >> n >> k;
	if (n + n - 1 < k)
		return cout << 0 << endl, 0;
	ll lo = 0, hi = n;
	while (hi - lo > 1) {
		ll mid = (hi + lo) / 2;
		if (mid + n >= k)
			hi = mid;
		else
			lo = mid;
	}
	ll idx = hi;
	lo = 0, hi = n;
	while (hi - lo > 1) {
		ll mid = (hi + lo) / 2;
		if (mid * 2 + 1 <= k)
			lo = mid;
		else
			hi = mid;
	}
	cout << lo - idx + 1 << endl;
}