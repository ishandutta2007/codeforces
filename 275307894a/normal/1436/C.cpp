#include<cstdio>
#define mod 1000000007
using namespace std;
int n,m,k,x,y,z,l,r,mid;
long long ans=1,pus,tot;
int main(){
	int i;
	scanf("%d%d%d",&n,&m,&k);
	pus=m-1;tot=n-m;
	l=0;r=n;
	while(l<r){
		mid=(l+r)>>1;
		if(mid<k) l=mid+1,ans=ans*pus%mod,pus--;
		else if(mid==k) l=mid+1;
		else r=mid,ans=ans*tot%mod,tot--; 
	}
	for(i=1;i<=tot+pus;i++) ans=ans*i%mod;
	printf("%lld\n",ans);
}