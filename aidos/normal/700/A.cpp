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
int n, l, v1, v2, k;
long double get(long double cc){
	long double lx = 0, rx = cc;
	for(int i = 0; i < 100; i++){
		long double mid =(lx+rx)/2;	
		if(mid * v1 + v2 * (cc - mid) >= l){
			lx = mid;
		}else rx = mid;
	}
	return rx;
}
bool check(long double cc){
	if(cc * v2 < l) return 0;
	if(cc * v1 >= l) return 1;
	long double g = get(cc);
	long double ad = 0.0;
	for(int i = 0; i < n; i+=k){
		if(ad > g){
			return 0;
		}
		ad += cc - g;
//		v2 * (cc-g) = v1 * t + v2 * t + v1 * (cc - g);
		ad += ((v2 - v1) * (cc - g))/(v1 + v2);
	}
	return 1;
}
void solve(){
	cin >> n >> l >> v1 >> v2 >> k;
	long double lx = 0, rx = 2e9;
	for(int i = 0; i < 100; i++){
		long double mid = (lx + rx) / 2;
		if(check(mid)){
			rx = mid;
		}else lx = mid;
	}
	printf("%.12lf\n", (double) rx);
}

int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Test case #%d\n", i);
      solve();
    }

    return 0;
}