#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,z,t;
long long ans,a[200039],maxn;
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=maxn=0;
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=2;i<=n;i++) ans+=abs(a[i]-a[i-1]);
		maxn=max(maxn,abs(a[1]-a[2]));
		maxn=max(maxn,abs(a[n]-a[n-1]));
		for(i=2;i<n;i++)maxn=max(maxn,abs(abs(a[i+1]-a[i-1])-(abs(a[i+1]-a[i])+abs(a[i-1]-a[i]))));
		printf("%lld\n",ans-maxn); 
	}
}