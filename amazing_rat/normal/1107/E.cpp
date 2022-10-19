#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=110;
int n,a[maxn];
ll dp[maxn][maxn][maxn];
char s[maxn];
ll dfs(int l,int r,int k) {
	if (dp[l][r][k]!=-1) return dp[l][r][k];
	if (l>r) return 0;
	if (l==r) return dp[l][r][k]=a[k+1];
	dp[l][r][k]=dfs(l,r-1,0)+a[k+1];
	for (int i=l;i<r;i++)
		if (s[i]==s[r])
			dp[l][r][k]=max(dp[l][r][k],dfs(l,i,k+1)+dfs(i+1,r-1,0));
	return dp[l][r][k];
}
int main() {
	read(n);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++) read(a[i]);
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",dfs(1,n,0));
	return 0;
}