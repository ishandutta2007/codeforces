#include<cstdio>
#define N 139
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,T,a[N],ans;
int main(){
	register int i;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=0;for(i=1;i<=n;i++) scanf("%d",&x),a[x]++;
		for(i=1;i<=n;i++)ans=max(ans,a[i]),a[i]=0;printf("%d\n",ans);
	}
}