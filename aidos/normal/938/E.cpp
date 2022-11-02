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
ll fact[2000100];
int mod = 1000*1000*1000+7;
int n;
int a[2000100];

ll binpow(ll x, int y){
	ll res = 1;
	while(y>0){
		if(y&1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

ll C(int n, int k){
	return fact[n] * binpow(fact[n-k] * 1ll*fact[k] % mod, mod-2) % mod;
}
void solve(){
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	//reverse(a, a + n);
	fact[0] = 1;
	for(ll i = 1; i <= 2*n; i++){
		fact[i] = fact[i-1] * i % mod;
	}
	ll ans = 0;
	for(int i = 0; i < n; ){
		int j = i;
		while(i < n && a[i] == a[j]) i++;
		if(i != n) {
			ans = (ans + ((((i-j) * 1ll * C(n, j) ) % mod * fact[j] % mod )* 1ll*a[j] % mod) * fact[n - j - 1] % mod)% mod;
		}
			
	}
	cout << ans << endl;
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