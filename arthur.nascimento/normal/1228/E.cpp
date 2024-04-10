#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define debug 

int n,k;

ll dp[255][255];
ll fat[300];
ll ifat[300];

ll exp(ll a,ll b){
	if(b == 0) return 1;
	ll k = exp(a,b/2);
	k = (k*k) % mod;
	if(b%2 == 1) k = (k*a) % mod;
	return k;
}

ll CC[300][300];
ll C(int n,int k){
	ll r = fat[n] * ifat[k];
	r %= mod;
	r *= ifat[n-k];
	r %= mod;
	//debug("C %d %d = %d\n",n,k,r);
	return r;
	
}
int tt = 0;
ll ek1[300];
ll ek[300];

ll go(int pos,int ok){
	if(pos == n)
		return (ok == n);
	ll &ans = dp[pos][ok];
	if(ans+1)
		return ans;
	ans = 0;
	
	for(int u=0;u<=n-ok;u++){
			ll mul = C(n-ok,u) ;
		//if(pos == 1 && u == 0 && ok == 0) debug("! %lld\n",mul);
		//mul *= go(pos+1,ok+u);
		mul %= mod;//if(pos == 1 && u == 0 && ok == 0) debug("! %lld\n",mul);
		mul *= ek[ok];//exp(k,ok);
		mul %= mod; 
		mul *= ek1[n-ok-u];//exp(k-1,n-ok-u);
		mul %= mod;
		if(pos == 1 && u == 2 && ok == 0) debug("! %lld\n",mul);
		if(u == 0)
			mul -= ek1[n];//exp(k-1,n);
		mul += mod;
		mul %= mod;
		mul *= go(pos+1,ok+u);
		mul %= mod;
		ans += mul;
		ans %= mod;
		if(pos == 1 && u == 2 && ok == 0) debug("! %lld %lld\n",mul,ans);
	
	}
	debug("%d %d -> %lld\n",pos,ok,ans);
	return ans;
}

main(){

	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&k);
	
	fat[0] = ifat[0] = 1;

	for(int i=0;i<=n;i++){
		ek[i] = exp(k,i);
		ek1[i] = exp(k-1,i);
	}
	for(int i=1;i<=n;i++){
		fat[i] = (fat[i-1]*i) % mod;
		ifat[i] = exp(fat[i],mod-2);
	}
	
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
			CC[i][j] = C(i,j);
	
	printf("%lld\n",go(0,0));

}