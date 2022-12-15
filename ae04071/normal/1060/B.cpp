#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const lli inf=1e15;

lli dp[15][2],a[15],n,lst;
int vis[15][2];

lli DP(int idx,int t) {
	if(vis[idx][t]) return dp[idx][t];
	vis[idx][t]=1;
	lli &ret=dp[idx][t];

	if(idx<lst) {
		if(t==1) return ret=-inf;
		else return ret=0;
	}
	ret=0;
	for(int i=0;i<10;i++) for(int j=0;j<10;j++) {
		if((i+j+t)%10!=a[idx]) continue;
		ret=max(ret,DP(idx-1,(i+j+t)/10)+i+j);
	}
	return ret;
}

int main() {
	scanf("%lld",&n);
	for(int i=14;i>=0 && n;i--) a[i]=n%10,n/=10,lst=i;

	memset(dp,-1,sizeof(dp));
	printf("%lld\n",DP(14,0));

	return 0;
}