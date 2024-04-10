#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,a[100039],b[100039],ans;
int main(){
	register int i;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=2;i<=n;i++) b[i]=a[i]-a[i-1]-1;
	sort(b+2,b+n+1);
	for(i=2;i<=n-k+1;i++) ans+=b[i];
	printf("%d\n",ans+n);
}