#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=5e5+123,inf=1e9,mod=1e9+7;
int n,m,k,ans,cntx;
ll a[maxn];
vector< pair<ll , pair< int ,int > > >vec;
void add(int &a,int b){
	a+=b;
	if(a>mod)
		a-=mod;
}
vector<int> g[maxn];
bool was[maxn];
void dfs(int v){
	if(was[v])
		return;
	was[v]=1;
	for(auto to:g[v])	
		dfs(to);
}
ll binpow(ll x,ll p){
	ll res=1;
	while(p){
		if(p&1)
			res=res*x%mod;
	 	x=x*x%mod;
	 	p/=2;
	}
	return res;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    	scanf("%lld",&a[i]);
	for(int i=0;i<m;i++){
		int v,u;
		scanf("%d%d",&u,&v);
		v--;u--;
		ll x=(a[v]^a[u]);
		vec.pb({x,{v,u}});
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();){
        vector< pair< int ,int> > d;
		int cnt=0,res=1;
		int j=i;
		while( j < vec.size() && vec[i].f==vec[j].f )
			d.pb(vec[j++].s);
		for(auto x:d){      
			g[x.f].pb(x.s);
			g[x.s].pb(x.f);
		}
		
		for(auto x:d)
			if( !was[x.f] ){
				dfs(x.f);
				add(res,res);
		    }     
		
		for(auto x:d){      
			if(was[x.f])
				cnt++;      
			if(was[x.s])
				cnt++;
			was[x.f]=0;
			was[x.s]=0;
			g[x.f].clear();
			g[x.s].clear();
		}
		res=1ll*res*binpow(2,n-cnt)%mod;
		add(ans,res);
		cntx++;
		i=j;	
	}
	ans=( binpow(2,n)*(binpow(2,k)-cntx)%mod + ans )%mod;
	ans=(ans+mod)%mod;
	printf("%d",ans);
	return 0;
}