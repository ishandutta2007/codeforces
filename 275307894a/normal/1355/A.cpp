#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
unsigned long long n,m,k,x,y,t,ans,tot,pus;
int main(){
	register int i;
	scanf("%llu",&t);
	while(t--){
		scanf("%llu%llu",&x,&y);
		for(i=2;i<=y;i++){
			ans=x;
			tot=0;pus=1e5;
			while(ans){
				tot=max(tot,ans%10);
				pus=min(pus,ans%10);
				ans/=10;
			}
			if(!pus) break;
			x+=tot*pus;
		}
		printf("%llu\n",x);
	}
}