#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,a[139];
int main(){
	register int i;
	scanf("%d%d",&n,&k);
	k=n-k+1;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%d\n",a[k]);
}