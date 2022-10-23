#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int n,T,t1[500005],t2[500005],t0[500005],bac[500005],l[500005],r[500005],dp[500005];
ll a[500005],s[500005];
pair<ll,int> p[500005];
void upd1(int x,int o){while(x<=n+1)t1[x]=max(t1[x],o),x+=(x&-x);}
void upd2(int x,int o){while(x<=n+1)t2[x]=max(t2[x],o),x+=(x&-x);}
int get1(int x){
	int o=-orz;
	while(x){
		o=max(o,t1[x]);
		x-=(x&-x);
	}
	return o;
}
int get2(int x){
	int o=-orz;
	while(x){
		o=max(o,t2[x]);
		x-=(x&-x);
	}
	return o;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%I64d",a+i),s[i]=s[i-1]+a[i],p[i]=mp(s[i],i);
		p[n+1]=mp(0,0);
		sort(p+1,p+n+2);
		for(int i=1;i<=n+1;++i){
			bac[p[i].second]=i;
			if(i==1||p[i].first!=p[i-1].first)l[i]=i;
			else l[i]=l[i-1];
		}
		for(int i=n+1;i;--i){
			if(i>n||p[i].first!=p[i+1].first)r[i]=i;
			else r[i]=r[i+1];
		}
		for(int i=1;i<=n+1;++i)t0[i]=t1[i]=t2[i]=dp[i]=-orz;
		dp[0]=0;
		for(int i=0;i<=n;++i){
			int k=bac[i];
			dp[i]=max(dp[i],t0[l[k]]);
			dp[i]=max(dp[i],get1(k)+i);
			dp[i]=max(dp[i],get2(n+2-k)-i);
			t0[l[k]]=max(t0[l[k]],dp[i]);
			upd1(r[k]+1,dp[i]-i);
			upd2(n+3-l[k],dp[i]+i);
		}
		printf("%d\n",dp[n]);
	}
    return 0;
}