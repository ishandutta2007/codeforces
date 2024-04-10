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
const int maxn = (int)2e5 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
int n, k;
int a[maxn];
ll calc() {
	ll s = 0;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		if(i>=k-1&&a[i] == a[i-k+1]) {
			return 0;
		}
	}
	ll ans = 1ll<<55;
	for(int i = 0; i < n; i++) {
		s += a[i];
		if(i >= k-1) ans = min(ans, a[i] * 1ll*k + (a[i]-1) *1ll* (i-k+1) - s);
		else {
			ll cur = sum - s - (a[i]+1) * 1ll * (n-k);
			ans = min(ans, a[i] * 1ll * (i+1) - s + cur - a[i]*1ll*(k-i-1));
		}
	}
	return ans;
}
void solve(){
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	ll ans = calc();
	int t=a[n-1];
	for(int i = 0; i < n; i++) {
		a[i] = t - a[i] + 1;
	}
	sort(a, a + n);
	ans = min(ans, calc());
	cout << ans << "\n";
}
int main () {

    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d: ", i);
      solve();
    }
    
    return 0;
}