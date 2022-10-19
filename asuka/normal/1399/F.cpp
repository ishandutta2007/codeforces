#include<bits/stdc++.h>
#define ll long long
#define N 6005
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,dp[N][N],b[N<<1],l[N],r[N];
VI e[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	cin>>t;
 	while(t--){
 		cin>>n;
 		int tot = 0;
 		rep(i,1,n) rep(j,1,n) dp[i][j] = 0;
 		rep(i,1,n) cin>>l[i]>>r[i];
 		rep(i,1,n) b[++tot] = l[i],b[++tot] = r[i];
 		sort(b+1,b+tot+1);tot = unique(b+1,b+tot+1)-b-1;
 		rep(i,1,tot) e[i].clear();
 		rep(i,1,n) l[i] = lower_bound(b+1,b+tot+1,l[i])-b;
 		rep(i,1,n) r[i] = lower_bound(b+1,b+tot+1,r[i])-b;
 		rep(i,1,n) e[l[i]].pb(r[i]);
 		rep(len,1,tot){
 			rep(i,1,tot-len+1){
 				int j = i+len-1;
 				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
 				for(auto v:e[i]){
 					if(v>=j) continue;
 					dp[i][j] = max(dp[i][j],dp[i][v]+dp[v+1][j]);
 				}
 				dp[i][j] += count(e[i].begin(),e[i].end(),j);
 			}
 		}
 		cout << dp[1][tot] << endl;
 	}
	return 0;
}