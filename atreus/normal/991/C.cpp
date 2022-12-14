#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const int Maxn = 5e3 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll n;

bool check (ll k) {
	ll a = 0, b = 0;
	ll tmp = n;
	while (tmp > 0) {
		a += min (k, tmp);
		tmp -= min (k, tmp);
		b += tmp / 10;
		tmp -= (tmp / 10);
	}
	return (a >= b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll l = 0, r = n;
	while (r - l > 1) { 
		ll mid = (r + l) / 2;
		if (check (mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
}