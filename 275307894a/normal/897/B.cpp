#include<cstdio>
using namespace std;
long long n,m,k,x,y,z,p,s[10039],sh,ans,tot;
int main(){
	register int i,j;
	scanf("%lld%lld",&n,&p);
	for(i=1;i<=n;i++){
		z=i;sh=0;
		while(z){
			s[++sh]=z%10;
			z/=10;
		}
		tot=0;
		for(j=sh;j;j--) tot=tot*10+s[j];
		for(j=1;j<=sh;j++) tot=tot*10+s[j];
		ans=(ans+tot)%p;
	}
	printf("%lld\n",ans);
}