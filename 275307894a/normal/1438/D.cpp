#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[1000039],ans,tot,pus;
int head,xs[1000039],ys[1000039],zs[1000039];
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),ans^=a[i];
	if(n%2==0&&ans) {printf("NO\n");return 0;}
	for(i=3;i<=n;i+=2) xs[++head]=i-2,ys[head]=i-1,zs[head]=i;
	for(i=2;i<n;i+=2) xs[++head]=i-1,ys[head]=i,zs[head]=n;
	printf("YES\n%d\n",head);
	for(i=1;i<=head;i++) printf("%d %d %d\n",xs[i],ys[i],zs[i]);
}