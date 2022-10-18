#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define AquA cin.tie(0);ios_base::sync_with_stdio(0);
#define fs first
#define sc second
#define p_q priority_queue
using namespace std;

int main(){
    AquA;
	const int A=1e7+7;
	vector<int> vis(A),pr,ans(A);
	ans[1]=1;
	for(int i=2;i<A;i++){
		if(!vis[i]){
			pr.push_back(i);
			ans[i]=i;
		}
		for(auto h:pr){
			if(h*i>=A){
				break;
			}
			vis[h*i]=1;
			if(ans[i]%h==0){
				ans[i*h]=ans[i]/h;
			}
			else{
				ans[i*h]=ans[i]*h;
			}
			if(i%h==0){
				break;
			}
		}
	}
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<int> v(n),lst,les(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
			v[i]=ans[v[i]];
		}
		auto p=v;
		sort(p.begin(),p.end());
		p.erase(unique(p.begin(),p.end()),p.end());
		for(auto &h:v){
			h=lower_bound(p.begin(),p.end(),h)-p.begin();
		}
		lst.resize(p.size(),-1);
		for(int i=0;i<n;i++){
			les[i]=lst[v[i]];
			lst[v[i]]=i;
		}
		vector<vector<pair<int,int> > > dp(n,vector<pair<int,int> >(k+2,{1e9,1e9}));
		dp[0][0]={1,0};
		for(int i=0;i<n-1;i++){
			for(int j=0;j<=k;j++){
				auto h=dp[i][j];
				if(les[i+1]<-h.sc){
					dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
					dp[i+1][j+1]=min(dp[i+1][j+1],pair<int,int>(dp[i][j].fs+1,-(i+1)));
				}
				else{
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
					dp[i+1][j]=min(dp[i+1][j],pair<int,int>(dp[i][j].fs+1,-(i+1)));
				}
			}
		}
		int ans=1e9;
		for(int i=0;i<=k;i++){
			ans=min(ans,dp[n-1][i].fs);
		}
		cout << ans << "\n";
	}
    return 0;
}