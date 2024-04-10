#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

inline lli _abs(lli a) {return a<0 ? -a : a;}
inline int _abs(int a) {return a<0 ? -a : a;}

int dp[1000001][5][5],n,m,cnt[1000001];
int DP(int idx,int a,int b) {
	int &ret=dp[idx][a][b];
	if(ret!=-1) return ret;

	ret=0;
	if(idx==m) return ret=0;
	
	for(int i=0;i<=min(cnt[idx],4);i++) {
		int rem=cnt[idx]-i,v=min({a,b,rem});
		ret = max(ret, DP(idx+1,b-v,i)+v+(rem-v)/3);
	}
	return ret;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		int v;
		scanf("%d",&v);
		cnt[v-1]++;
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",DP(0,0,0));
	
	return 0;
}