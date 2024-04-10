#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,a[3],b[3],ans,tot,now;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&n);
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	scanf("%d%d%d",&b[0],&b[1],&b[2]);
	tot=min(a[0],b[1])+min(a[1],b[2])+min(a[2],b[0]);
	ans=n-min(a[0],n-b[1])-min(a[1],n-b[2])-min(a[2],n-b[0]);
	printf("%d %d\n",ans,tot);
}