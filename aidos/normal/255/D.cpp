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
#include <bitset>
#include <unordered_map>

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

const int inf = 100100;
const int maxn = (int) 1e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
ll n, c, x, y;

ll calc(ll a, ll b, ll d) {
	if(a>b) swap(a, b);
	if(a > d) {
		return (d+1)*(d+2)/2;
	}
	if(a+b-2 <= d) return a * b;
	ll cur = (a) * (a+1)/2;
	d -= a-1;
	if(d <= b-a) return cur + a * d;
	cur += (b-a)*a;
	d -= b - a;
	a -= 1;
	cur += a * (a+1)/2;
	cur -= (a-d) * (a-d+1)/2;
	return cur;
}
void solve(){
	cin >> n >> x >> y >> c;
	ll l = 0, r = 2 * n, res = 0;
	//l = 2, r = 2;
	//for(ll mid = 0; mid <= 10; mid++){
	while(l <=r) {
		ll mid = (l + r)/2;
		ll cur = calc(x, y, mid) + calc(x, n-y+1, mid) + calc(n-x+1, y, mid) + calc(n-x+1, n-y+1, mid);
		cur -= min(x, mid+1);
		cur -= min(y, mid+1);
		cur -= min(n-x+1, mid+1);
		cur -= min(n-y+1, mid+1);
		cur += 1;
		//cout << mid << " "<<cur << "\n";
		if(cur >= c) {
			res = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	cout << res << "\n";
}	

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}