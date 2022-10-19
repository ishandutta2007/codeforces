#include<cstdio>
#include<cstring>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long n,m,k,x,y,z,a[500039],ans,tot,t;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans=-1e20;
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(i=0;i<=5;i++){
			tot=1;
			for(j=1;j<=i;j++) tot*=a[j];
			for(j=n;j>=n-4+i;j--) tot*=a[j];
			ans=max(ans,tot);
		}
		printf("%lld\n",ans);
	}
}