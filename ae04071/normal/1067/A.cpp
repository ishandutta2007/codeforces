#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef long long lli;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

const int mod=998244353;
int dp[2][201][2],n,a[100000];

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);

	if(a[0]==-1){
		for(int i=1;i<=200;i++)
			dp[0][i][0]=1;
	} else {
		dp[0][a[0]][0]=1;
	}

	int cur=1,pr=0;
	for(int i=1;i<n;i++) {
		int sum=0,ps=0;
		for(int j=1;j<=200;j++) {
			sum = (sum+dp[pr][j][1])%mod;
			dp[cur][j][0]=dp[cur][j][1]=0;
		}

		for(int j=1;j<=200;j++) {
			if(!(a[i]!=-1 && j!=a[i])){
				dp[cur][j][0]=ps;
				dp[cur][j][1]=(sum+dp[pr][j][0])%mod;
			}
			
			sum = (sum-dp[pr][j][1]+mod)%mod;
			ps=(ps+dp[pr][j][0])%mod;
			ps=(ps+dp[pr][j][1])%mod;
		}
		swap(cur,pr);
	}

	int ans=0;
	for(int i=1;i<=200;i++){
		ans=(ans+dp[pr][i][1])%mod;
	}

	printf("%d\n",ans);

	return 0;
}