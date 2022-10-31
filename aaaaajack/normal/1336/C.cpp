#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define Q 998244353 
#define N 3010
using namespace std;
int dp[N][N];
char s[N],t[N];
int main(){
	scanf("%s%s",s,t);
	int n=strlen(s),m=strlen(t),ans=0;
	for(int i=0;i<=n;i++) dp[0][i]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			if(j>=m || t[j]==s[i]){
				dp[i+1][j+1]+=dp[i][j];
				dp[i+1][j+1]%=Q;
			}
			if(j-i>0 && (j-i-1>=m || t[j-i-1]==s[i])){
				dp[i+1][j]+=dp[i][j];
				dp[i+1][j]%=Q;
			}
		}
	}
	for(int i=m;i<=n;i++){
		ans=(ans+dp[i][i])%Q;
	}
	printf("%d\n",ans);
	return 0;
}