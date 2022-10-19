#include<bits/stdc++.h>
#define int long long
#define N
#define mod 998244353
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
using namespace std;
int n,dp[2][415][415][3][3],sum[405][405],c[27];
void inc(int &a,int b){a = (a+b)%mod;}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld",&n);
 	rep(i,1,26) scanf("%lld",&c[i]);
 	int cur = 1; dp[cur][0][0][2][2] = 1;
 	rep(i,1,n){
 		memset(dp[cur^1],0,sizeof dp[cur^1]);
 		rep(j,0,i){
 			rep(k,0,i-j){
 				rep(p,0,2){
 					inc(dp[cur^1][j+1][k][p][0],dp[cur][j][k][1][p]+dp[cur][j][k][2][p]);
 					inc(dp[cur^1][j][k+1][p][1],dp[cur][j][k][0][p]+dp[cur][j][k][2][p]);
 					inc(dp[cur^1][j][k][p][2],24*(dp[cur][j][k][0][p]+dp[cur][j][k][1][p])+((i>2)?23:24)*(dp[cur][j][k][2][p]));
 				}
 			}
 		}
 		cur ^= 1;
 	}
 	  // printf("%d\n",dp[cur][15][17][0][0]);
 	rep(j,0,n){
 		rep(k,0,n){
 			rep(p,0,2) rep(q,0,2) inc(sum[j][k],dp[cur][j][k][p][q]);
 		}
 	}
 	per(j,0,n) per(k,0,n) inc(sum[j][k],sum[j+1][k]+sum[j][k+1]+mod-sum[j+1][k+1]);
 	int ans = 26*26;
 	rep(i,3,n) ans = (ans*25)%mod;
 	rep(i,1,26) inc(ans,mod-sum[c[i]+1][0]);
 	rep(i,1,26) rep(j,i+1,26) inc(ans,sum[c[i]+1][c[j]+1]);
 	printf("%lld\n",ans);
	return 0;
}
/*
aabbaabbaa
*/