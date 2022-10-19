#include<cstdio> 
#define ll long long
#define I inline
#define N 5000
using namespace std;
int n,now,last,pus,vis[N+5];ll x[N+5],y[N+5];
I ll dis(int a,int b){return (x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]);}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);now=last=1;printf("1 ");
	for(i=1;i<n;i++){
		for(pus=now,vis[now]=1,j=1;j<=n;j++) !vis[j]&&dis(now,j)>dis(now,pus)&&(pus=j);
		printf("%d ",pus);last=now;now=pus;
	}
}