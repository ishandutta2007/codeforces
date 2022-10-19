#include<bits/stdc++.h>
#define int long long
#define N 1005
#define mod 998244353
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,k,b[N],dp[N][N],pre[N][N],res[N*100];
signed main(){
	//freopen(".in","r",stdin);
	//freopen("tmp.out","w",stdout);
 	scanf("%lld%lld",&n,&k);
 	rep(i,1,n) scanf("%lld",&b[i]);
 	b[0] = -inf;
 	sort(b+1,b+n+1);
 	//cout << n*k*(b[n]/(k-1)) <<  endl;
 	for(int d = 1;d*(k-1) <= b[n];++d){
 		//cout << d << endl;
 		dp[0][0] = pre[0][0] = 1;
 		int pos = 0;
 		rep(i,1,n){
 			while(b[i]-d >= b[pos]) pos++;
 			rep(j,0,k){
 				//cout << i << ' ' << j << endl;
 				if(j) dp[i][j] = pre[pos-1][j-1];
 				pre[i][j] = (pre[i-1][j] + dp[i][j])%mod;
 			}
 			res[d] = (res[d]+dp[i][k])%mod;
 		}
 	}
 	int ans = 0;
 	for(int d = 1;d*(k-1) <= b[n];++d)
 		ans = (ans + 1ll*(res[d]-res[d+1]+mod)%mod*d%mod)%mod;
 	printf("%lld\n",ans);
	return 0;
}