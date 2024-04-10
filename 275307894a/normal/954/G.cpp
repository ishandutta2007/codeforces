#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,x,y,z,rs;
long long l,r,mid,k,f[500039],g[500039],ans;
inline int check(long long mid){
	register int i;
	for(i=1;i<=n;i++)f[i]=0;
	ans=0;
	for(i=1;i<=n;i++){
		f[i]+=f[i-1];
		if(g[i]+f[i]<mid){
			if(i+2*rs+1<=n) f[i+2*rs+1]-=mid-(g[i]+f[i]);
			ans+=mid-(g[i]+f[i]);
			f[i]=mid-g[i];
			if(ans>k) return 0;
		}
	}
	return 1;
}
int main(){
	//freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d%lld",&n,&rs,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		f[max(i-rs,1)]+=x;
		if(i+rs+1<=n)f[i+rs+1]-=x;
	}
	for(i=1;i<=n;i++) f[i]+=f[i-1];
	for(i=1;i<=n;i++) g[i]=f[i];
	l=0;r=2e18;
	while(l+1<r){
		mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%lld\n",l);
}