#include <bits/stdc++.h>
using namespace std;

char s[3001],t[3001];
int ds[3001][3001],dp[3001][3001],n,m,pw[3001];

const int MOD = 998244353;

int DP(int idx,int len) {
	if(len==0) return pw[idx+1];

	int &ret=ds[idx][len];
	if(ret!=-1) return ret;

	if(idx+1==len) return dp[m-len][m-1];

	ret = DP(idx-1,len);
	if(len && s[idx] == t[m-len]) ret = (ret + DP(idx-1,len-1))%MOD;

	return ret;
}

int main() {
	scanf("%s%s",s,t);
	n=strlen(s);
	m=strlen(t);
	
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%MOD;

	for(int i=0;i<m;i++) dp[i][i] = 2*(s[0]==t[i]);
	for(int l=1;l<m;l++) {
		for(int i=0,j=i+l-1;j<m;i++,j++) {
			if(i && t[i-1]==s[l]) dp[i-1][j] = (dp[i-1][j] + dp[i][j])%MOD;
			if(j<m && t[j+1]==s[l]) dp[i][j+1] = (dp[i][j+1] + dp[i][j])%MOD;
		}
	}
	memset(ds,-1,sizeof(ds));
	
	int ans=0;
	for(int i=m;i<=n;i++) ans = (ans + DP(i-1,m))%MOD;
	printf("%d\n",ans);

	return 0;
}