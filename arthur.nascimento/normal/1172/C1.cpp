#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define pb push_back
#define maxn 400400
#define debug 
#define ll long long

int type[maxn];
ll E[maxn];
ll aux[maxn];

ll exp(ll a,ll b){
	if(b == 0) return 1;
	ll k = exp(a,b/2);
	k = (k*k)%mod;
	if(b%2==1) k = (k*a)%mod;
	return k;
}

ll invv(ll x){
	return exp(x,mod-2);
}

ll dp[3030][3030];

ll su = 0, sd = 0;

ll get(ll up,ll down){
	
	if(up == 0 && down == 0)
		return 1;
	if(up < 0 || down < 0)
		return 0;
	
	ll &ret = dp[up][down];
	if(ret+1) return ret;
	
		
	ll U = get(up-1,down);
	ll qtdU = su + up-1;
	ll qtdD = sd - down;
	
	U *= qtdU;
	U %= mod;
	U *= invv(qtdU+qtdD);
	U %= mod;
	
	
	ll D = get(up,down-1);
	qtdU = su + up;
	qtdD = sd - (down-1);
	
	D *= qtdD;
	D %= mod;
	D *= invv(qtdU+qtdD);
	D %= mod;
	
	ret = (U+D)%mod;
	debug("dp %lld %lld = %lld\n",up,down,(3*ret)%mod);
	return ret;
	
}


ll prob[maxn];

ll ans[maxn];

int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++)
		scanf("%d",type+i);
	
	for(int i=0;i<n;i++){
		scanf("%lld",E+i);
		if(type[i] == 1) su += E[i];
		else sd += E[i];	
	}
	
	memset(dp,-1,sizeof(dp));
	
	for(int i=0;i<=k;i++){
		//debug("prob[%d] = %lld\n",i,prob[i]);
		prob[i] = get(i,k-i);
		
	}
	
	for(int i=0;i<n;i++){
	//	if(type[i] == 1)
	//		ans[i] = (E[i] * prob[0]) % mod;
	//	else
	//		ans[i] = (E[i] * prob[k]) % mod;
	}
	
	for(int j=0;j<=k;j++){
		
	
		ll invU = su+j, invD = sd-j;
		
		invU = invv(invU);
		invD = invv(invD);
		
		
		//debug("inv %lld\n",inv);
		
		for(int i=0;i<n;i++){
			

			if(type[i] == 1){
				ll add = (E[i]*invU) % mod;
				
				ans[i] += (prob[j] * E[i]) % mod;
				debug("%d += %lld\n",i,(prob[j] * E[i]) % mod);
				E[i] = (E[i] + add) % mod;
				ans[i] %= mod;
			}
			else {
				ll add = (E[i]*invD) % mod;
			 	//E[i] = (E[i] - add + mod) % mod;
			 	ans[i] += (prob[k-j] * E[i]) % mod;
			 	ans[i] %= mod;
				debug("%d += %lld\n",i,(prob[k-j] * E[i]) % mod);
				E[i] = (E[i] - add + mod) % mod;
			 }
			
			//ans[i] += 
			
		}
		
	}
	
	for(int i=0;i<n;i++)
		printf("%lld\n",ans[i]);

}