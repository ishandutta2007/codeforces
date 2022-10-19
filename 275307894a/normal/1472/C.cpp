#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t,a[200039];
long long f[200039],ans; 
int main(){
	//freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=n;i;i--){
			if(i+a[i]<=n) f[i]=f[i+a[i]]+a[i];
			else f[i]=a[i];
			ans=max(ans,f[i]);
		}
		printf("%lld\n",ans);
	}
}