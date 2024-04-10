// High above the clouds there is a rainbow...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=110, maxn2=1010 ,inf=1e9 + 10;

vector<int> v[maxn];
int ds[maxn][maxn];

int a[maxn2],b[maxn2],c[maxn2],d[maxn2],e[maxn2];

template<int maxn, ll inf> struct Flow{
    vector<pair<int,pll> > v[maxn];
    vector<int> rv[maxn];
    int arr[maxn], pt[maxn], par[maxn];
    ll ds[maxn];
    bool inq[maxn];
    
    void add(int a,int b,ll c,ll d){
	rv[a].PB(sz(v[b]));
	rv[b].PB(sz(v[a]));
	
	v[a].PB({b,{c,d}});
	v[b].PB({a,{0,-d}});
    }
    bool spfa(int src,int snk){
	fill( ds, ds+maxn, inf);
	memset(inq,0,sizeof inq);
	
	int L=0,R=0;
	arr[R++]= src;
	ds[src]=0;
	inq[src]=1;
	
	while(L!=R){  
	    int u=arr[L++];
	    if(L==maxn) L=0;
	    inq[u]=0;
	    
	    for(auto x:v[u]){
		if(x.S.F==0) continue;
		if(ds[x.F]<=ds[u] + x.S.S) continue;
		ds[x.F]= ds[u] + x.S.S;
		if(inq[x.F]==0) inq[x.F]=1, arr[R++]=x.F, R=(R==maxn ? 0 : R);
		par[x.F]= u;
	    }
	}
	return ds[snk]!=inf;
    }
    ll go(int src,int snk){
	ll cst=0;
	while(snk!=src){
	    int u=par[snk], y=snk;
	    for(int i=0;i<sz(v[u]);i++){
		if(v[u][i].F == y && v[u][i].S.F>0){
		    v[u][i].S.F--;
		    v[y][ rv[u][i] ].S.F++;
		    cst+= v[u][i].S.S;
		    break;
		}
	    }
	    snk=par[snk];
	}
	return cst;
    }
}; Flow<2010,1000000000000000> flw;


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    
    int n,m; cin>>n>>m;

    for(int i=0;i<m;i++){
	int a,b; cin>>a>>b; --a,--b;
	v[a].PB(b);
	v[b].PB(a);
    }
    for(int i=0;i<n;i++){
	queue<int> q;
	for(int j=0;j<n;j++)
	    ds[i][j]= inf;
	q.push(i);
	ds[i][i]=0;

	while(sz(q)){
	    int u= q.front();
	    q.pop();	    
	    for(int y:v[u]){
		if(ds[i][y]==inf) ds[i][y]= ds[i][u]+1, q.push(y);
	    }
	}
    }

    int A,B;   cin>>n>>m>>A>>B;

    int src=n+m, snk=n+m+1;
    
    for(int i=0;i<n;i++){
	flw.add(src,i,1,-A);
    }
    for(int i=0;i<m;i++){
	flw.add(n+i,snk,1,0);
    }

    for(int i=0;i<n;i++){
	cin>>a[i]>>b[i]>>c[i]; --a[i];
    }
    for(int i=0;i<m;i++){
	cin>>d[i]>>e[i]; --d[i];
    }
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(ds[a[i]][d[j]]<=c[i] && b[i]>=e[j])
		flw.add(i,j+n,1,0);
	}
    }

    ll ans= 1ll*B*n, nw=0;
    
    for(int w=1;w<=n;w++){
	if(flw.spfa(src,snk) == 0) break;
	nw-=flw.go(src,snk);
	ans=min(ans,1ll*B*(n-w) + nw );
    }
    ans=min(ans, nw);
    
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")