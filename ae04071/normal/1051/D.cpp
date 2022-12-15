#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctype.h>
#include <utility>

using namespace std;
typedef pair<int,int> pii;
const int mod=998244353;

int dp[1000][2001][4];
int m,k;

int get_new(int i,int j) {
	int c=2;
	if( (j&1) == (j>>1) ) c--;
	if( (i&1) == (j&1) ) c--;
	if( (i>>1) == (j>>1) ) c--;
	return max(0,c);
}
int DP(int idx,int cnt,int s) {
	if(idx==m) return cnt==k;

	int &ret=dp[idx][cnt][s];
	if(ret!=-1) return ret;

	ret=0;
	for(int i=0;i<4;i++) {
		ret = (ret + DP(idx+1,cnt+get_new(s,i),i))%mod;
	}
	return ret;
}

int main() {
	scanf("%d%d",&m,&k);
	memset(dp,-1,sizeof(dp));
	
	int ans=0;
	for(int i=0;i<4;i++) {
		ans = (ans + DP(1, ( (i&1)^(i>>1) )+1, i))%mod;
	}
	printf("%d\n",ans);
	return 0;
}