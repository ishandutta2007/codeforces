#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,g[300100][2],suf[300100][2],sum[300100],res,tot;
signed main(){
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)scanf("%I64d",&g[i][0]);
	for(int i=1;i<=n;i++)scanf("%I64d",&g[i][1]);
	for(int i=n;i;i--)sum[i]=sum[i+1]+g[i][0]+g[i][1];
	for(int i=n;i;i--){
		suf[i][0]=suf[i+1][0]+sum[i+1];
		suf[i][0]+=g[i][0]+g[i][1]*(n-i+1)*2;
		suf[i][1]=suf[i+1][1]+sum[i+1];
		suf[i][1]+=g[i][1]+g[i][0]*(n-i+1)*2;
	}
//	for(int i=1;i<=n;i++)printf("%d ",suf[i][!(i&1)]);puts("");
	for(int i=1;i<=n;i++)suf[i][0]+=sum[i]*(i-1)*2,suf[i][1]+=sum[i]*(i-1)*2;
//	for(int i=1;i<=n;i++)printf("%d ",suf[i][!(i&1)]);puts("");
	res=suf[1][0];
	for(int i=1;i<=n;i++){
		tot+=i*2*g[i][i&1]+(i*2-1)*g[i][!(i&1)];
		res=max(res,tot+suf[i+1][i&1]);
	}
	printf("%I64d\n",res-sum[1]);
	return 0;
}