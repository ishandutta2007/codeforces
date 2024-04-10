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
#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define sc second
#define pii pair<int,int>
#define pis pair<int, string>
#define psi pair<string, int>
using namespace std;
int a, b, n;
ll fact[1000100];
bool isGood(int sum){
	while(sum > 0){
		if(sum % 10 != a && sum %10!=b) return 0;
		sum/=10;
	}
	return 1;
}
ll mod = (ll)(1e9 + 7);
ll bPow(ll c, ll d){
	if(d == 0) return 1;
	if(d & 1) return (c * 1ll * bPow(c, d - 1)) % mod;
	ll x = bPow(c, d/2);
	return (x * 1ll * x) % mod;
}
ll get(int n, int x){
	return (fact[n] * 1ll * bPow((fact[n-x] * 1ll * fact[x]) % mod, mod - 2) )% mod;
}

int main () {
    #ifdef LOCAL
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    cin >> a >> b >> n;
    ll ans = 0;
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
    	fact[i] = (fact[i-1] * 1ll * i) % mod;
    }
    for(int i = 0; i <= n; i++){
    	if(isGood(a * i + (n - i) * b)){
    		ans = (ans + get(n, i)) % mod;
    	}
    }
    cout << ans << endl;
    #ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif
    return 0;
}