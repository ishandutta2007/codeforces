#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
const int N=1000005,inf=2e9;
int n,ans,d[N],cn[N];
ll K;
template<class I>
il I Min(I p,I q){return p<q?p:q;}
il bool ck(ct k){
	it i,j,dep;rll sum,now;
	for(i=1;i<=n;++i) d[i]=cn[i]=0;
	for(i=2,now=1,sum=K,dep=0;i<=n;)
		for(now*=k,++dep,j=1;j<=now&&i<=n;++i,++j) ++cn[dep],d[i]=dep,sum-=dep;
	if(sum<0) return 0;
	i=n;while(sum&&i) ++dep,i-=(cn[d[i]]==1),now=Min(sum,(ll) dep-d[i]),--cn[d[i]],d[i]+=now,++cn[d[i]],sum-=now,--i;
	return 1;
}
il void ms(){
	it l=1,r=n,mid;
	while(l<=r) mid=l+r>>1,ck(mid)?ans=mid,r=mid-1:l=mid+1;
}
int main(){ 
	scanf("%d%lld",&n,&K);it i,j;
	if((K<(n-1<<1|1)) || (K>((n+1ll)*n>>1))) return puts("No"),0;
	K-=n,puts("Yes"),ms(),ck(ans);
	d[1]=0,std::sort(d+2,d+1+n);
	for(i=1;i<=n;++i) cn[i]=0;
	for(i=2,j=1;i<=n;++i){
		while(j<=n&&(d[j]!=d[i]-1||cn[j]==ans)) ++j;
		printf("%d ",j),++cn[j];
	}
	return 0;
}