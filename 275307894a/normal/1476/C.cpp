#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
using namespace std;
int n,m,k,x,y,z,t,c[1000039],a[1000039],b[1000039];
long long ans,tot,pus;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){ans=pus=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&c[i]);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		ans=pus=abs(a[2]-b[2])+1;
		for(i=3;i<=n;i++){
			ans=max(ans,pus+c[i-1]);
			if(a[i]==b[i]) pus=1;
			else pus+=c[i-1]-(abs(a[i]-b[i])-1),pus=max(pus,abs(a[i]-b[i])+1);
		}
		ans=max(ans,pus+c[n]);
		printf("%lld\n",ans);
	}
}