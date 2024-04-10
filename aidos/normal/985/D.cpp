#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
 
#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()
 
const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
ll n, d;
bool can(ll x) {
	if(x <= d) {		
		ll c  = (n * 2)/(x+1);
		if(c < x) return 1;
		if(x * (x+1) >= 2 * n) return 1;
		return 0;
	}
	//d, d + 1, d+2, ... c, c-1, ..., 1
	//d .... d d-1, ... 1
	ll y = x - (d-1);
	ll c = (n*2)/d;
	if(c < d-1) return 1;
	ll nn = n - d*(d-1)/2;
	if(nn<=0) return 1;
	ll h = nn/y;
	if(h < d-1) return 1;
	nn -= y * (d-1);
	if(nn <= 0) return 1;
	if(y % 2 == 1) {
		ll k = (y+1)/2;
		if(k >= nn) return 1;
		nn -= k;
		y--;
	}
	if(y == 0) return 0;
	y/=2;
	h = nn/y;
	if(h < y + 1) return 1;
	nn -= y * (y+1);
	if(nn <= 0) return 1;
	return 0;
}
int main () {
	cin >> n >> d;
	ll l = 1, r = n;
	ll res = -1;
	while(l <= r) {
		ll mid = (l + r)/2;
		if(can(mid)) {
			r = mid-1;
			res = mid;
		}
		else {
			l = mid+1;
		}
	}
	cout << res << "\n";

    return 0;
}