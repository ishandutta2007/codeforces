#include<bits/stdc++.h>
#define ll long long
#define N 500015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,a[N],dp[N],l[N],r[N],cnt[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&n);
 	rep(i,1,n) scanf("%d",&a[i]),r[a[i]] = i;
 	per(i,1,n) l[a[i]] = i;
 	per(i,1,n){
 		dp[i] = dp[i+1]; cnt[a[i]]++;
 		if(i == l[a[i]]) dp[i] = max(dp[i],dp[r[a[i]] + 1] + cnt[a[i]]);
 		else dp[i] = max(dp[i],cnt[a[i]]);
 		// printf("i: %d dp: %d\n",i,dp[i]);
 	}
 	printf("%d\n",n-dp[1]);
	return 0;
}