#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int t,ans,tot,pus,a,b,c,d;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ans=a*(b-d-1);
		ans=max(ans,a*d);
		ans=max(ans,b*(a-c-1));
		ans=max(ans,b*c);
		printf("%d\n",ans);
	}
}