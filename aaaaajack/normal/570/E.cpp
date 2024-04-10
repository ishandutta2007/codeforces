#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 510
#define Q 1000000007
using namespace std;
long long dp[2][N][N];
char s[N][N];
int main(){
	int p=0,ls,rs,n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	if((n+m)&1){
		ls=(n+m+2)/2;
		rs=(n+m+3)/2;
		for(int i=max(1,ls-n);i<=min(m,ls-1);i++){
			if(ls-i<n&&s[ls-i][i]==s[ls-i+1][i]) dp[0][i][i]=1;
			if(i<m&&s[ls-i][i]==s[ls-i][i+1]) dp[0][i][i+1]=1;
		}
		ls--;
		rs++;
	}
	else{
		for(int i=0;i<N;i++){
			dp[0][i][i]=1;
		}
		ls=(n+m+2)/2-1;
		rs=(n+m+2)/2+1;
	}
	while(ls>=2){
		for(int i=max(1,ls-n);i<=min(m,ls-1);i++){
			for(int j=max(1,rs-n);j<=min(m,rs-1);j++){
				if(s[ls-i][i]!=s[rs-j][j]) continue;
				if(i<m&&j>1) dp[p^1][i][j]+=dp[p][i+1][j-1];
				if(ls-i<n&&rs-j>1) dp[p^1][i][j]+=dp[p][i][j];
				if(ls-i<n&&j>1) dp[p^1][i][j]+=dp[p][i][j-1];
				if(i<m&&rs-j>1) dp[p^1][i][j]+=dp[p][i+1][j];
				dp[p^1][i][j]%=Q;
			}
		}
		ls--;
		rs++;
		memset(dp[p],0,sizeof(dp[p]));
		p^=1;
	}
	printf("%I64d\n",dp[p][1][m]);
	return 0;
}