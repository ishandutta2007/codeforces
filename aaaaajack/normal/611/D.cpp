#include<cstdio>
#include<algorithm>
#define Q 1000000007
#define N 5010
using namespace std;
int dp[N][N];
int diff[N][N];
char s[N];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(s[i-j+1]=='0'){
				dp[i][j]=dp[i][j-1];
				continue;
			}
			if(i-j<j) dp[i][j]=(dp[i][j-1]+dp[i-j][i-j])%Q;
			else{
				for(int k=max(i-j+1,diff[i-1][j]);k<=i;k++){
					if(s[k]!=s[k-j]){
						diff[i][j]=k;
						break;
					}
				}
				if(!diff[i][j]) diff[i][j]=i+1;
				if(diff[i][j]<=i&&s[diff[i][j]]>s[diff[i][j]-j]) dp[i][j]=(dp[i][j-1]+dp[i-j][j])%Q;
				else dp[i][j]=(dp[i][j-1]+dp[i-j][j-1])%Q;
			}
		}
	}
	printf("%d\n",dp[n][n]);
	return 0;
}