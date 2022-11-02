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
#define forit(s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()

const int inf = (1ll << 31) - 1;
const int maxn = (int) 1e5 + 10;
const int mod = 1000000007;

using namespace std;


ll n, k;
ll fact[100100];
ll rfact[100100];
ll sum[100100];
ll binpow(ll x, int p){
	if(p == 0) return 1;
	if(p& 1) return binpow(x, p-1) * 1ll * x % mod;
	return binpow(x * 1ll * x % mod, p/2);
}
ll get(int n, int k){
	if( k < 0) return 0;
	if( k>n) return 0;
	return fact[n] *1ll * rfact[k] % mod * 1ll * rfact[n-k] % mod;
}

int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif

    string s;
    cin >> n >> k >> s;
    
    fact[0] = 1;
    rfact[0]=binpow(fact[0], mod-2);
    for(int i = 1; i <= n; i++){
    	fact[i] = fact[i-1] * 1ll * i % mod;	
	    rfact[i]=binpow(fact[i], mod-2);
    }
    if(k == 0){
    	ll ans=0;
    	for(int j =0;  j<n; j++){
    		ans = (ans * 10ll + s[j] - '0') % mod;
    	}
    	cout << ans << endl;
    	return 0;
    }
    //cerr <<"a1\n";
	ll ans = 0;
	ll d = 0;
    for(int i = 0; i<n; i++){
    	d = (d* 10ll + s[i] - '0') % mod;
    	////ans = (ans + d * 1ll * get(n - i - 2, k-1)) % mod;
    }
    //cout << ans << endl;
    sum[0] = 0;
    for(int i =1; i<=n; i++){
    	sum[i] = (sum[i-1] + get(n - i - 1, k-1) * 1ll * binpow(10, i-1) % mod) % mod;
    }
    for(int i = 0; i<n-1; i++){
    	ans =(ans+ (s[i]  - '0' ) * 1ll * sum[n-i-1] % mod) % mod;
    }
    //cout<<ans<<endl;
    int col = 2;
    d = 0;
    for(int i=n-1; i>=0; i--){
    	d = ((s[i] - '0' ) * 1ll * binpow(10, n-i-1)+d) % mod;
//    	cout << d << endl;
    	ans = (ans + get(i-1, k-1) * 1ll * d) % mod;
    	col++;
    }
    cout << ans << endl;




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}