#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[100039],p[100039],ans;
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		if(i&1) p[i]=a[n/2+i/2+1];
		else p[i]=a[i/2];
	}
	for(i=2;i<n;i++)  if(p[i]<p[i-1]&&p[i]<p[i+1]) ans++;
	printf("%d\n",ans);
	for(i=1;i<=n;i++) printf("%d ",p[i]);
}