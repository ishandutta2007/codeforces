#include<cstdio>
using namespace std;
int n,k,y,z,t;
long long m,ans,x;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld",&n,&m);
		ans=0;
		for(i=1;i<=n;i++) scanf("%lld",&x),ans+=x;
		if(m==ans) printf("YES\n");
		else printf("NO\n");
	}
}