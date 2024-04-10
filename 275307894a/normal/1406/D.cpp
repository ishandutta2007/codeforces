#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
long long n,m,k,x,y,z,l,r,mid,a[100039],q[100039],pus,tot,ans,nows,qs[100039];
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=2;i<=n;i++) q[i]=a[i]-a[i-1],qs[i]=max(q[i],0);
	for(i=2;i<=n;i++) ans+=qs[i];
	if((a[1]+ans)/2.0<0) printf("%lld\n",(long long)((a[1]+ans)/2.0));
	else printf("%lld\n",(long long)((a[1]+ans)/2.0+0.5));
	scanf("%lld",&m);
	for(i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x==1) a[x]+=z;
		else{
			q[x]+=z;
			ans+=max(0,q[x])-qs[x];
			qs[x]=max(0,q[x]);
		}
		if(y!=n){
			q[y+1]-=z;
			ans+=max(0,q[y+1])-qs[y+1];
			qs[y+1]=max(0,q[y+1]);
		}
		if((a[1]+ans)/2.0<0) printf("%lld\n",(long long)((a[1]+ans)/2.0));
		else printf("%lld\n",(long long)((a[1]+ans)/2.0+0.5));
	}
}