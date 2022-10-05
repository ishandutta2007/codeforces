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

const int maxn=3e5+123,INF=1e9,mod=1e9+7,N=2e5+123;
struct btr{
	map< int ,ll > dp;
	set< pair<ll,int> > st;
	ll mn,add;
};
vector< int> g[maxn];
int n,m;
btr a[maxn];
                  
void Merge( btr &a, btr &b  ){
	if( a.dp.size()<b.dp.size() )
		swap(a,b);
	
	
	ll x=a.add,y=b.add;
	a.add+=b.mn+y;
	b.add+=a.mn+x;
	for( auto x: b.dp ){
		int v = x.f;
		ll c = x.s + b.add - a.add;
		if( !a.dp.count(v) || a.dp[v] > c ){
			a.st.erase({a.dp[v],v});
            a.dp[v] = c;
			a.st.insert({a.dp[v],v});
        }
	}
	if( !a.st.empty() )
		a.mn = a.st.begin()->f;
}
void dfs(int v,int p){
	if( !a[v].st.empty() )
		a[v].mn = a[v].st.begin()->f;
	btr tmp;
	bool flag = 0;
	for( auto to:g[v] ){
			if( to==p )
			continue;
		dfs(to,v);
		if( !flag )
			swap( tmp , a[to] );
        else
        	Merge(tmp,a[to]);
        
        flag = 1;     
		a[to].dp.clear();
		a[to].st.clear();
	}
	if( flag ){  
		
		for( auto x:a[v].dp ){
			int u = x.f;
			ll c = x.s + tmp.mn ;
			if( !tmp.dp.count(u) || tmp.dp[u] > c ){
				tmp.st.erase({tmp.dp[u],u});
            	tmp.dp[u] = c;
				tmp.st.insert({tmp.dp[u],u});
        	}
		}
		swap( a[v], tmp);
	}
    
	
	if( v!=1 && a[v].dp.count(v) ){
		a[v].st.erase({a[v].dp[v],v});
		a[v].dp.erase(v);
		if( !a[v].st.empty() )
			a[v].mn = a[v].st.begin()->f;
	}

	if( a[v].st.empty() ){      
		cerr << v << endl;
		printf("-1");
		exit(0);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	if( n==1 ){      
		printf("0");
		exit(0);
	}
	for(int i=1;i<n;i++){
		int v,u;
		scanf("%d%d",&v,&u);
		g[v].pb(u);
		g[u].pb(v);
	}
	for(int i=0;i<m;i++){
		int u,v,c;
		scanf("%d%d%d",&v,&u,&c);
		if( !a[v].dp.count(u) || a[v].dp[u] > c ){
			a[v].st.erase({a[v].dp[u],u});
        	a[v].dp[u] = c;
			a[v].st.insert({a[v].dp[u],u});
        }
	}
	dfs(1,1);
	printf("%lld", 0ll + a[1].mn + a[1].add );
}