// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=1e5+123,inf=1e8,mod=1e9+7,block=500;
vector< pair < ll ,ll > > g[maxn];
ll n,m,q,a[maxn],sz[maxn],sum[maxn],add[maxn];
ll cnt,id[maxn],x;
bitset< maxn > bt[block+123];
vector<int>v[maxn],p;
int main(){                 
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>sz[i];
		for(int j=0;j<sz[i];j++){
			cin>>x;
			v[i].pb(x);
			sum[i]+=a[x];
		}	
		
		if(sz[i]>block){
			for(int j=0;j<v[i].size();j++){
				bt[p.size()][v[i][j]]=1;
			}
			id[i]=p.size();
			p.pb(i);
		}
	}    
	for(int i=1;i<=m;i++){
		if(sz[i]>block){
			for(int j=0;j<p.size();j++)
				g[i].pb(mp( p[j] , ( bt[j] & bt[id[i]] ).count() ) );
		}else{
			for(int j=0;j<p.size();j++){
				int cnt=0;
				for(int q=0;q<v[i].size();q++)
					cnt+=bt[j][v[i][q]] ;
				g[i].pb(mp(p[j],cnt));
			}
		}
	}   
	while(q--){
		char ch;
		ll k,x;
		cin>>ch;
		if(ch=='+'){
			cin>>k>>x;
			if( sz[k]<=block ){
				
				for(int i=0;i<v[k].size();i++)
					a[v[k][i]]+=x;

				for(int i=0;i<g[k].size();i++){
            		int to=g[k][i].f;
            		sum[to]+=g[k][i].s*x;
            	}
            
            }else
				add[k]+=x;
		}else{
			cin>>k;
			ll ans=0;
			if( sz[k]>block ){   
				ans=sum[k];
			}else{
				for(int i=0;i<v[k].size();i++)
					ans+=a[v[k][i]];
            }
            for(int i=0;i<g[k].size();i++){
            	int to=g[k][i].f;
            	ans+=g[k][i].s*add[to];
            }
            cout<<ans<<endl;
		}
	}
}