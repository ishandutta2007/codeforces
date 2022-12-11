#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
#define y1 sda
using namespace std;    
const int N = int(3e5) + 10, mod = int(1e9)  + 7; 
const ll inf = (ll)(1e18);
int t;
ll x,y,p,q;

int main () {
	cin >> t;
	while(t--){
		cin >> x >> y >> p >> q;
		if(p == 0){
			if(x > 0) puts("-1");
			else puts("0");
			continue;
		}
		ll ans = inf;
		ll k = (x + p - 1) / p;
		ll a = k * p  - x;
		if(y + a <= k * q){
			ans = min(ans, a + k * q - y - a);
		}
		else{
			if(q > p){
				ll v = q - p;
				ll res = y + a - k * q;
				ll t = (res + v - 1) / v;
				ans = min(ans, a + t * p + (k + t) * q - y - a - t * p);
			}
		}
		if(ans == inf) ans = -1;
		cout << ans << endl;
	}

return 0;
}