#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
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
const int maxn = 1e5 + 100;
const int  mod = 1e9 + 7;
const ll inf = (1ll << 62);
ll n, h, tot = 0;

bool check1 (ll x){
	ll tot = x * (x + 1) / 2;
	tot *= 2;
	tot -= h * (h - 1) / 2;
	return (tot >= n);
}

bool check (ll x){
	ll tot = x * (x + 1) / 2;
	tot *= 2;
	tot -= x;
	tot -= h * (h - 1) / 2;
	return (tot >= n);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> h;
	ll cur = 0;
	ll l = 0, r = (1ll << 31) - 1;
	while (r - l > 1){
		ll mid = (l + r) / 2;
		if (mid * (mid + 1) / 2 >= n)
			r = mid;
		else
			l = mid;
	}
	cur = r;
	if (cur <= h)
		return cout << cur << endl, 0;
	l = 0, r = (1ll << 31) - 1;
	while (r - l > 1){
		ll mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	ll ans = 2 * r - h;
	l = 0, r = (1ll << 31) - 1;
	while (r - l > 1){
		ll mid = (l + r) / 2;
		if (check1(mid))
			r = mid;
		else
			l = mid;
	}
	ans = min (ans, 2 * r - h + 1);
	cout << ans << endl;
}