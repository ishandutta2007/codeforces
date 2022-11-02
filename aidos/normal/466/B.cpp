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

const int inf = (1ll << 25) - 1;
const int maxn = (int) 2000+20;
const int mod = (int) 1e9 + 7;
const int maxd = (int) 700700;
using namespace std;
ll n, a, b;
void solve(){
	cin >> n >> a >> b;
	if(6*n <= a * b) {
		cout << a * b << "\n";
		cout << a << " " << b << "\n";
		return;
	}
	ll ans = 1e18, x, y;
	for(int i = 0; i < 1e6; i++) {
		ll A = a + i;
		ll B  = max((6*n + a + i-1)/(a+i), b);
		if(A * B < ans) {
			ans = A * B;
			x = a + i;
			y = B;
		}
		B = b + i;
		A = max((6*n + b + i-1)/(b+i), a);
		if(A * B < ans) {
			ans = A * B;
			x = A;
			y = B;
		}
	}
	cout << ans << "\n";
	cout << x <<  " " << y  << "\n";
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