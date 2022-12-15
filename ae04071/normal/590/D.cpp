#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
using pii=pair<int,int>;
using lli = long long;

const int inf=1e9;

int n,k,s,a[151],dp[2][151][5626];
inline int pw(int v) {return v*v;}
int main() {
	scanf("%d%d%d",&n,&k,&s);
	for(int i=1;i<=n;i++) scanf("%d",a+i);

	int cur=1,pr=0,ans=inf;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<=i;j++) for(int k=0;k<=pw((i+1)/2);k++) dp[cur][j][k] = inf;
		for(int j=0;j<i;j++) for(int k=0;k<=pw(i/2);k++) {
			dp[cur][j][k] = min(dp[cur][j][k], dp[pr][j][k]);
			dp[cur][j+1][k+i-j-1] = min(dp[cur][j+1][k+i-j-1],dp[pr][j][k]+a[i]);
		}
		
		if(i>=k) {
			for(int t=0;t<=min(s,pw((i+1)/2));t++) ans=min(ans,dp[cur][k][t]);
		}
		swap(cur,pr);
	}
	printf("%d\n",ans);

	return 0;
}