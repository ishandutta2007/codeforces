#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define nm "A" 
#define stdi freopen(nm".in","r",stdin);
#define stdo freopen(nm".out","w",stdout);
#define IO stdi stdo                   
#define ll long long                   
#define ld long double                                                                                                            
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=3e5+123,N=2e6+123,mod=1e9+7; 
vector< pair < int , int > >g[maxn];
int n,dp[maxn],pre[maxn];
ll sum(int l, int r){
	return 1ll*r*(r+1)/2-l*(l-1)/2;
}
ll get(vector<ll> v){
    sort(v.begin(),v.end());
    ll res=0,i=0;
    while(true){
    	bool u=1;
    	while(i<v.size() && v[i]==res)
    		u=0,i++;
    	if(u)
    		break;
    	res++;
    }
    return res;
}
int main(){           
	cin>>n;
	for(int i=1;i<=n;i++){
		int j=i+1;
		while( sum(i,j)<=n ){
			g[sum(i,j)].pb(mp(i,j));
			j++;
		}

	}           
	for(int i=1;i<=n;i++){
		vector<ll>v;
		for(int j=0;j<g[i].size();j++){
			int l=g[i][j].f,r=g[i][j].s;
			v.pb( (pre[r]^pre[l-1]) );
		}	
		dp[i]=get(v);
		pre[i]= (pre[i-1]^dp[i]) ;
	}
	if(dp[n]==0){
		cout<<-1;
		return 0;
	}            
	int ans=1e9;
	for(int i=0;i<g[n].size();i++){
		int l=g[n][i].f,r=g[n][i].s;
		if( (pre[r]^pre[l-1])==0 )
			ans=min(ans,r-l+1);
	}
	cout<<ans;
}