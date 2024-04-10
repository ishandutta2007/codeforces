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

ll a, b;
ll n, k;
char c[300100];
const int mod = 1000 * 1000 * 1000 + 9;
ll binpow(ll x, ll y){
	x %= mod;
	x += mod;
	x %= mod;
	ll res = 1;
	while(y > 0){
		if(y & 1) res = (res * x) % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

ll calc(ll g, ll y){
	if(y == 0) return 1;
	if(y % 2 == 0) return (calc(g, y-1) + binpow(g, y)) % mod;
	return (binpow(g, (y+1)/2) + 1) * calc(g, y/2) % mod;
}
void solve(){
	cin >> n >> a >> b >> k;
	scanf("%s", c);
	ll cur = binpow(a, n);
	ll ans = 0;
	b = b * binpow(a, mod-2) % mod;
	//n++;
	ll g = (n+1)/k;
	ll bb = binpow(b, k);
		
	for(int i = 0; i < k; i++){
		//i, i + k, i + 2 * k,
		//ll g = (n-i)/k;
		if(c[i] == '+')
			ans = (ans + binpow(b, i) % mod) % mod;
		else ans = (ans - binpow(b, i) % mod) % mod;
		ans += mod;
		ans %= mod;
			ans %= mod;
		ans += mod;
		ans %= mod;
		
		
	} 
	ans = (ans * 1ll * calc(bb, g-1)) % mod;
	ans *= cur;
	ans %= mod;
	ans += mod;
	cout << ans % mod;
	
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