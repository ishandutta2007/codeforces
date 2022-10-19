#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll exp(ll a,ll b){
	if(b == 0) return 1;
	ll k = exp(a,b/2);
	k = (k*k) % mod;
	if(b%2 == 1) k = (k*a) % mod;
	return k;
}

ll ans = 1;

int pr(int p){
	if(p == 1) return 0;
	for(int i=2;i*i<=p;i++)
		if(p%i == 0) return 0;
	return 1;
}

ll go(int p,ll n){
	if(!pr(p)) return 0;
	ll u = 0;
	while(n){
		u += n/p;
		n /= p;
	}
	//printf("%d %lld\n",p,u);
	ans *= exp(p,u);
	ans %= mod;

}
main(){
	ll x,n;
	cin >> x >> n;
	for(int i=1;i*i<=x;i++)
		if(x%i == 0){
			
			go(i,n);
			if(i*i != x) go(x/i,n);
		
		}
		
	cout << ans << endl;

}