#include<bits/stdc++.h>
using namespace std;
long long a[5009],b[5009];
int main(){
	int T,n,i,j,k;
	long long ans=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=0;memset(b,0,n*8+8);
		for(i=1;i<=n;++i)scanf("%lld",a+i);
		for(i=1;i<=n;++i){
			ans+=max(0ll,a[i]-b[i]-1);
			for(j=min((long long)n,a[i]+i);j>i+1;--j)++b[j];
			b[i+1]+=max(0ll,b[i]-a[i]+1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}