#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
const int N=1000005;
int T,n,a[N],k,w[N],q[N];
int main(){ 
	scanf("%d",&T);it i;
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;++i) scanf("%d",&a[i]);
		for(i=1;i<=k;++i) scanf("%d",&w[i]);
		std::sort(w+1,w+1+k),std::sort(a+1,a+1+n);
		register long long ans=0;it now=n+1,cnum=0;
		for(i=1;i<=k;++i){
			--now;
			if(w[i]==1) ans+=a[now]+a[now];
			else --w[i],ans+=a[now],q[++cnum]=w[i];
		}
		it pos=cnum,cn=0;
		for(i=1,cn=1;pos&&i<=now;++i,++cn){
			if(cn==1) ans+=a[i];
		//	printf("cn=%d q[pos]=%d\n",cn,q[pos]);
			if(cn==q[pos]) cn=0,--pos;
		}
		printf("%lld\n",ans);
	}
	return 0;
}