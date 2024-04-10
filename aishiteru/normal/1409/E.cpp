#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
const int N=1000005;
int T,n,k,a[N],pre[N],suf[N],f[N],g[N];
il int Max(ct p,ct q){return p>q?p:q;}
int main(){
	scanf("%d",&T);it i,x;
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;++i) scanf("%d",&a[i]),f[i]=g[i]=pre[i]=suf[i]=0;pre[0]=suf[n+1]=0;
		for(i=1;i<=n;++i) scanf("%d",&x);
		std::sort(a+1,a+1+n);it ans=0;
		for(i=1;i<=n;++i) f[i]=std::lower_bound(a+1,a+1+n,a[i]-k)-a,g[f[i]]=i;
	//	for(i=1;i<=n;++i) printf("%d\n",f[i]);
		for(i=1;i<=n;++i) pre[i]=Max(pre[i-1],i-f[i]+1);
		for(i=n;i;--i) suf[i]=Max(suf[i+1],g[i]-i+1);
		for(i=1;i<=n;++i) ans=Max(ans,pre[i]+suf[i+1]);
		printf("%d\n",ans);
	}
	return 0;
}