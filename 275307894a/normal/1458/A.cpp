#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,t;
long long a[200039],b[200039],ans,tot,pus;
int main(){
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=m;i++) scanf("%lld",&b[i]);
	if(n==1){
		for(i=1;i<=m;i++)printf("%lld ",a[1]+b[i]);
	}
	else{
		ans=abs(a[1]-a[2]);
		for(i=2;i<n;i++) ans=__gcd(ans,abs(a[i]-a[i+1]));
		for(i=1;i<=m;i++) printf("%lld ",__gcd(ans,b[i]+a[1])); 
	}
}