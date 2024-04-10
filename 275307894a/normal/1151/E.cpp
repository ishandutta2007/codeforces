#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b)) 
using namespace std;
int n,m,k,x,y,z,a[100038];
long long ans;
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),ans+=(long long)a[i]*(n-a[i]+1);
	for(i=1;i<n;i++) ans-=(long long) min(a[i],a[i+1])*(n-max(a[i],a[i+1])+1);
	printf("%lld\n",ans);
}