#include<cstdio>
using namespace std;
int m,k,t;
long long x,y,z,now,ans,n;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		now=1;ans=0;
		while(now<=n){
			ans+=n/now;
			now*=2;
		}
		printf("%lld\n",ans);
	}
}