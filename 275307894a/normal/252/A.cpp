#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[139],ans,q[139],n;
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),q[i]=q[i-1]^a[i];
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++) ans=max(ans,q[j]^q[i-1]);
	}
	printf("%d",ans);
}