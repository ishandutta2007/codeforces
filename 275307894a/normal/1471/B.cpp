#include<cstdio>
#define N 100000
#define ll long long
using namespace std;
int T,n,a[N+5],z[N+5],y[N+5],x,flag;ll ans;
int main(){
//	freopen("1.in","r",stdin);
	register int i;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);ans=0;
		for(i=1;i<=n;i++)scanf("%d",&y[i]),z[i]=y[i],ans+=z[i];
		while(1){
			flag=0;
			for(i=1;i<=n;i++) if(z[i]%x==0)ans+=y[i],z[i]/=x;
			else{flag=1;break;}
			if(flag) break;
		}
		printf("%lld\n",ans);
	}
}