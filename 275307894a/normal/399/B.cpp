#include<cstdio>
using namespace std;
long long ans,tot,pus,n;
char s;
int main(){
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		s=getchar();
		while(s<'A'||s>'Z') s=getchar();
		if(s=='B') ans+=1ll<<(i-1);
	}
	printf("%lld\n",ans);
}