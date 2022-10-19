#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t;
int a[1000039];
long long l,r,mid,ans,tot,pus;
inline int check(long long mid){
	for(int i=n;i>=2;i--){
		if(a[i]*100.0/(mid-a[i])>k)return 0; 
		mid-=a[i];
	}
	return 1;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);tot=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),tot+=a[i];
		l=tot-1;r=1e18;
		while(l+1<r){
			mid=l+r>>1;
			if(check(mid)) r=mid;
			else l=mid;
		}
		printf("%lld\n",r-tot);
	}
}