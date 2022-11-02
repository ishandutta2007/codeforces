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
const int maxn = (int)1e6 + 10; //maximum + 10
const int mod = (int) 1e9 + 7;
using namespace std;
ll n, m;
ll sum(ll x, ll y) {
	if(x>y) return 0;
	ll a = (y-x+1);
	ll b = (y+x);
	if(a % 2 == 0) a/=2;
	else b/=2;
	a %= mod;
	b %= mod;
	return a * b % mod;
}
ll get(ll x, ll m) {
	ll y = sqrt(x);
	ll ans = 0;
	for(ll i = 1; i <= y && i <= m; i++) {
		ans = (ans + (n/i) % mod * i % mod) % mod;
	}
	for(ll i = 1; i <= y; i++) {
		ll lf = n/(i+1);
		ll rs = n/i;
		ans = (ans + sum(max(lf+1, y + 1), min(rs, m)) * i % mod) % mod;
	}
	return ans;
}
void solve(){
	cin >> n >> m;
	ll ans = (n%mod) * (m % mod) % mod;
	ans = (ans + mod - get(n, min(n, m))) % mod;
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