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
int n,m,a[N],b[N],c[N],dp[N][(1<<10)+5];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,m) scanf("%d",&b[i]);
	dp[0][0] = 1; int all = (1<<9)-1;
	rep(i,0,n-1){
		rep(s,0,all){
			rep(j,1,m){
				dp[i+1][s|(a[i+1]&b[j])] |= dp[i][s];
			}
		}
	}
	rep(s,0,all){
		if(dp[n][s]){
			printf("%d\n",s);
			return 0;
		}
	}
	//printf("%d\n",ans);
	return 0;
}