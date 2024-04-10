#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,a0) memset(a,a0,sizeof(a))
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=110; typedef long long ll; const int inf=~0u>>2; typedef pair<int,int> pii;
#define int ll
int T,n,m;
int in[N][N],dp[N][N];
set<int> st;
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m; st.clear();
		repeat(i,0,n)
		repeat(j,0,m)
			cin>>in[i][j],in[i][j]-=i+j,st.insert(in[i][j]);
		ll ans=1e18;
		for(auto k:st){
			repeat(i,0,n)
			repeat(j,0,m){
				int a=in[i][j]-k;
				dp[i][j]=1e18;
				if(a<0)continue;
				if(i==0 && j==0)dp[i][j]=a;
				if(i!=0)dp[i][j]=min(dp[i][j],dp[i-1][j]+a);
				if(j!=0)dp[i][j]=min(dp[i][j],dp[i][j-1]+a);
			}
			ans=min(ans,dp[n-1][m-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}