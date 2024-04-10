#include<cstdio>
using namespace std;
long long n,m,k,x,y,z,a[100039],q[100039];
int main(){
	register int i;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=2;i<n;i++) q[i]=a[i+1]-a[i-1]-2,q[i]+=q[i-1];
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		if(x==y) printf("%lld\n",k-1);
		else{
			printf("%lld\n",a[x+1]-2+q[y-1]-q[x]+k-a[y-1]-1);
		}
	}
}