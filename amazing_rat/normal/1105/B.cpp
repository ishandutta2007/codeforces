#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,k,ans,dp[maxn];
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	scanf("%s",s+1);
	for (char c='a';c<='z';c++) {
		int cnt=0; memset(dp,0,sizeof(dp));
		for (int i=1;i<=n;i++) {
			if (s[i]==c) cnt++; else cnt=0;
			dp[i]=dp[i-1];
			if (cnt>=k) dp[i]=max(dp[i],dp[i-k]+1);
			ans=max(ans,dp[i]);
		}
	} printf("%d\n",ans);
	return 0;
}