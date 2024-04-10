#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli mod=998244353;
lli dp[19][1<<10][2][2],val[19],a[19],de[19][1<<10][2][2];
int k;

lli DP(int idx,int s,int f,int t) {
	lli &ret=dp[idx][s][f][t];
	if(ret!=-1) return ret;

	ret=0;
	if(idx==0) {
		int c=0;
		for(int i=0;i<10;i++) 
			c+=(s>>i&1);
		return ret=(c<=k);
	}

	for(int i=0;i<=(f?9:a[idx]);i++) {
		int ns=(t || i!=0) ? (s|1<<i) : 0,nt = (t || i!=0);
		ret = (ret+DP(idx-1,ns,f|(i<a[idx]),nt))%mod;
		de[idx][s][f][t] = (de[idx][s][f][t] + val[idx]*i%mod*DP(idx-1,ns,f|(i<a[idx]),nt)%mod + de[idx-1][ns][f|(i<a[idx])][nt])%mod;
	}
	return ret;
}
lli proc(lli v){
	if(v==0) return 0;

	int n=1;
	while(v) {
		a[n++]=v%10; v/=10;
	}
	memset(dp,-1,sizeof(dp));
	memset(de,0,sizeof(de));
	DP(n-1,0,0,0);
	return de[n-1][0][0][0];
}
int main() {
	lli l,r;
	scanf("%lld%lld%d",&l,&r,&k);
	val[1]=1;
	for(int i=2;i<19;i++)
		val[i] = val[i-1]*10%mod;
	printf("%lld\n",((proc(r)-proc(l-1))%mod+mod)%mod);
	return 0;
}