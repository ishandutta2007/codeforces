#include<cstdio>
using namespace std;
long long t,n,m,k,x,y,z,now,ans,pus,tot;
int main(){
	register int i;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld%lld",&x,&y,&k);
		ans=k*y;
		printf("%lld\n",(ans+k-1)/(x-1)+((ans+k-1)%(x-1)==0?0:1)+k);
	}
}