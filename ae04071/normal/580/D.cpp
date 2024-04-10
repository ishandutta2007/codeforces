#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;

int n,m,k;
int adj[20][20],cost[20];
lli dp[1<<18][18];

lli DP(int s,int idx) {
	lli &ret=dp[s][idx];
	if(ret!=-1) return ret;
	ret=0;

	int cnt=0;
	for(int i=0;i<n;i++) if(s>>i&1) cnt++;
	if(cnt==m) return ret=0;
	for(int i=0;i<n;i++) if(!(s>>i&1)) {
		ret=max(ret,DP(s|1<<i,i)+adj[idx][i]+cost[i]);
	}
	return ret;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d",cost+i);
	for(int i=0;i<k;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c); a--; b--;
		adj[a][b]=c;
	}
	memset(dp,-1,sizeof(dp));

	lli ans=0;
	for(int i=0;i<n;i++) ans=max(ans,DP(1<<i,i)+cost[i]);
	printf("%lld\n",ans);
	return 0;
}