#include<cstdio>
using namespace std;
long long n,m,k,x,y,t,ans;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		if(m<=n-1) ans=(m+1)*m/2;
		else ans=(n-1)*n/2+1;
		printf("%lld\n",ans);
	}
}