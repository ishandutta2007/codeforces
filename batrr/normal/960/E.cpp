#include <bits/stdc++.h>
 
#define nm "" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                                                                                                            
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define Bystro ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e5+123,N=2e6+123,mod=1e9+7;
vector<int> g[maxn];
ll n,a[maxn],ans;       
ll dp1[maxn],cnt1[maxn];
ll dp2[maxn],cnt2[maxn];
void dfs(int v, int p){                                
	dp1[v]=a[v];
	cnt1[v]=1;     
	 
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(to!=p){
			dfs(to,v);
			ll res=0;
			res+=(dp1[v]*cnt2[to]+dp2[to]*cnt1[v])%mod;
            res+=(dp2[v]*cnt1[to]+dp1[to]*cnt2[v])%mod;
   			//cout<<res<<" "<<v<<" "<<to<<endl;
   			ans=(ans+res)%mod;
   			
   			dp1[v]+=dp2[to]+cnt2[to]*a[v];
			cnt1[v]+=cnt2[to];

			dp2[v]+=dp1[to]-cnt1[to]*a[v];
			cnt2[v]+=cnt1[to];
			            
			dp1[v]%=mod;
			dp2[v]%=mod;
		}
	}   
	                                            /*
    cout<<ans<<endl;
	cout<<v<<" "<<p<<endl;      
	cout<<dp1[v]<<" "<<cnt1[v]<<endl;
	cout<<dp2[v]<<" "<<cnt2[v]<<endl;
	                                               */
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v; 
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,1);
	ans=(ans*2%mod+mod)%mod;
	for(int i=1;i<=n;i++)
		ans+=a[i];
	cout<<(ans%mod+mod)%mod;                          
}