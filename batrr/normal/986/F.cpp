// Tima the best
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 

#define ll long long                   
#define ld long double                
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,inf=1e9,N=3e7+5e6,INF=1e18,mod=1e9+7;
vector< pair < ll ,ll > >v,g[maxn];
vector< ll > prime;
bool used[N+13];
ll t,dis[maxn],n[maxn],k[maxn];
map< pair< ll ,ll > , bool > ans;
ll binpow(ll x, ll n, ll mod){
    ll res = 1;
    while(n){
        if(n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	#endif
	for(int i=2;i<=N;i++){
		if(!used[i]){
			prime.pb(i);;
			for(ll j=1ll*i*i;j<N;j+=i)
				used[j]=1;
		}
	}
	scanf("%lld",&t);
	for(int i=0;i<t;i++){
		scanf("%lld%lld",&n[i],&k[i]);
		v.pb(mp(k[i],n[i]));	
	}
	sort(v.begin(),v.end());
	for(int i=0;i<t;){
		ll k=v[i].f,x=v[i].f; 
		vector< ll > vn,p;
		
		while(i<=t && k==v[i].f) 
			vn.pb(v[i++].s);
		
		for(int i = 0; i < prime.size(); i++) {
        	if(x % prime[i] == 0) {
        	    p.pb(prime[i]);
        	    while(x % prime[i] == 0)
        	    	 x /= prime[i];
        	}
       	}
    	if(x > 1) 
    		p.pb(x);	
    	
    	if(p.size()==1){
			for(int i=0;i<vn.size();i++)
				ans[mp(vn[i],k)]= (vn[i]%p[0]==0);
		}
        if(p.size()==2){
			ll x=p[0],y=p[1];
			for(int i=0;i<vn.size();i++){
				ll n=vn[i],a,b;
				b=n%x*binpow(y,x-2,x)%x;
                ans[mp(n,k)]= (n>=b*y);
        	}	
		}
        if(p.size()>=3){
        	for(int i=0;i<p[0];i++){
        		g[i].clear();     
        		for(int j=0;j<p.size();j++)
        			g[i].pb( mp( (i+p[j])%p[0],p[j]) );
        		dis[i]=INF;
        	}
        	
        	set< pair< ll ,ll > >st;
        	dis[0]=0;
        	st.insert(mp(0,0));
        	while(!st.empty()){
        		ll v=(*st.begin()).s;
        		st.erase(st.begin());
        		for(int i=0;i<g[v].size();i++){
        			ll to=g[v][i].f,w=g[v][i].s;
        			if( dis[to]>dis[v]+w ){      
        				st.erase(mp(dis[to],to));
        				dis[to]=dis[v]+w;
        				st.insert(mp(dis[to],to));
        			}
        		}
        	}
        	for(int i=0;i<vn.size();i++)
        		ans[mp(vn[i],k)]=  ( vn[i]>=dis[vn[i]%p[0]] );
		
		}
    }                            
    for(int i=0;i<t;i++)
    	if(ans[mp(n[i],k[i])]) 
    		puts("YES");
    	else
    		puts("NO");
}