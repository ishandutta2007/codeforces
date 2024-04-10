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

using namespace std;
ll k, d, t;

bool ok(double x){
	if(k > d){
	ll g = (k + d - 1)/d;
	g *= d;
	double st = g - k;
	ll T = x/g;
	double c = st/(2.0 * t) + ((double)k)/t;
	c *= T;
	x = x - g * T;
	if(k < x) c += ((double)k)/t + (x - k)/(2.0 * t);
	else c += ((double)x)/t;
	return c >= 1.0;
	}else{
		ll T = x/d;
		double c = (d - k * 1.0)/(2.0 * t) + ((double)k)/t;
		c *= T;
		x = x - d * T;
		if(k < x) c += ((double)k)/t + (x - k)/(2.0 * t);
		else c += ((double)x)/t;
	return c >= 1.0;
	}
}
void solve(){
	cin >> k >> d >> t;
	double l = 0, r = 2 * t + 1;
	for(int i = 0; i < 500; i++){
		double mid = (l + r)/2;
		if(ok(mid)) r = mid;
		else l = mid;
	}
	printf("%.15lf\n", r);
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}