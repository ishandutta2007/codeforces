#include<cstdio>
using namespace std;
int b[100039],tot,ans,a[100039],n,k;
int main(){
	register int i;
	scanf("%d%d",&b[1],&k);
	b[0]=1;
	scanf("%d",&a[1]);
	for(i=2;i<=k;i++) scanf("%d",&a[i]),a[i]%=2,b[i]=b[1]*b[i-1]%2;
	for(i=1;i<=k;i++)ans=(ans+a[i]*b[k-i])%2;
	if(ans) printf("odd");
	else printf("even");
}