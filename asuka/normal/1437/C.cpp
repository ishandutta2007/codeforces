#include<bits/stdc++.h>
#define ll long long
#define N 205
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,a[N],dp[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		memset(dp,0x3f,sizeof dp);
		dp[1] = 0;
		rep(i,1,n*2){
			per(j,2,n+1) dp[j] = min(dp[j],dp[j-1]+abs(a[j-1]-i));
		}
		printf("%d\n",dp[n+1]);
	}
	return 0;
}