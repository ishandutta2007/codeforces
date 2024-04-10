#include<cstdio>
using namespace std;
long long t,n,m,k,x,y,z,ans,tot,pus;
int main(){
	register long long i;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&x);ans=0;
		for(i=1;i<=x;i=2*i+1){
			if(x<i*(i+1)/2) break;
			ans++;x-=i*(i+1)/2;
		}
		printf("%lld\n",ans);
	}
}