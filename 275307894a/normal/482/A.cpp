#include<cstdio>
using namespace std;
int n,m,k;
int main(){
	register int i;
	scanf("%d%d",&n,&k);m=n+1;
	for(i=1;i<=k;i++) printf("%d ",(i&1)?i/2+1:n-i/2+1),m=(i&1)?i/2+1:n-i/2+1;
	if(m>n/2)for(i=m-1;i>n-m+1;i--) printf("%d ",i);
	else for(i=m+1;i<=n-m+1;i++) printf("%d ",i);
}