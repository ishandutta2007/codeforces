#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef long long lli;

int n,a[100001],dp[100001];
int _abs(int a) {return a<0 ? -a : a;}

int DP(int cur) {
	int &ret=dp[cur];
	if(ret!=-1) return ret;

	ret=1;
	for(int i=cur-a[cur];i>=0;i-=a[cur]) if(a[i]>a[cur]) 
		ret=min(ret,DP(i));
	for(int i=cur+a[cur];i<n;i+=a[cur]) if(a[i]>a[cur])
		ret=min(ret,DP(i));

	ret=1-ret;
	return ret;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);

	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++) printf("%c",DP(i) ? 'A' : 'B');

	return 0;
}