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

const int inf = (1 << 29) - 1;
const int maxn = (int)1e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;

int n, k;
int a[maxn];
bool can(long double x) {
	long double l = 0, r = 0;
	for(int i=0; i < n; i++) {
		if(a[i] < x) l += x-a[i];
		else r += a[i] - x;
	}
	if(r - r * k/100 >= l) return 1;
	return 0;
}
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	long double l = 0, r = 1000;
	for(int it = 0; it < 100; it++) {
		long double mid = (l + r)/2;
		if(can(mid)) {
			l = mid;
		}else {
			r = mid;
		}
	}
	printf("%.12lf\n", (double)r);
}
int main () {

	int t = 1;
	//scanf("%d", &t);
	for(int i=1; i<=t; i++){
		//printf("Case #%d: ", i);
		solve();
	}
    return 0;
}