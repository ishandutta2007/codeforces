#include<cstdio>
#define mod 1000000007
using namespace std;
int ans=1,tot,pus,n,m,k,a[200039],f[200039],s[200039],head;
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=2;i<=n+1;i++){
		if(!f[i]) s[++head]=i;
		for(j=1;j<=head&&s[j]*i<=n+1;j++){
			f[i*s[j]]=1;
			if(i%s[j]==0) break;
		}
	}
	if(n<=2) printf("1\n");
	else printf("2\n");
	for(i=2;i<=n+1;i++) printf("%d ",f[i]+1);
}