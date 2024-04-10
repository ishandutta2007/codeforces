#include<cstdio>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,a[39],head,ans,f[39];
int main(){
	register int i,j;
	scanf("%d",&n);
	f[0]=1;
	for(i=1;i<=9;i++) f[i]=f[i-1]*10;
	while(n){
		a[++head]=n%10;
		n/=10;
	}
	for(i=1;i<=head;i++) k=max(k,a[i]);
	printf("%d\n",k);
	for(i=1;i<=k;i++){
		ans=0;
		for(j=head;j>=1;j--){
			if(a[j]) ans+=f[j-1],a[j]--;
		}
		printf("%d ",ans);
	}
}