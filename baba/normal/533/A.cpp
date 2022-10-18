//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int N = int(5e5)+10;
const int INF = int(2e9)+10;
VI g[N];
VII affect[N];
int H[N],miners[N],A[N],T[N],ST[2][4*N],lazy[4*N],n;
set<II> S;
#define lc (x<<1)
#define rc (x<<1)|1
inline void push(int x,int l,int r){
	ST[0][x]+=lazy[x];ST[1][x]+=(r-l)*lazy[x];
	if(l==r-1)lazy[x]=0;
	if(!lazy[x])return;
	lazy[lc]+=lazy[x];lazy[rc]+=lazy[x];
	lazy[x]=0;
}
inline void up(int x){
	ST[0][x]=min(ST[0][lc],ST[0][rc]);
	ST[1][x]=ST[1][lc] + ST[1][rc];
}
inline void build(int l = 1,int r = n+1,int x = 1){
	lazy[x]=0;
	if(l==r-1)return void(ST[0][x]=ST[1][x]=A[l]);
	int m = (l+r)/2;
	build(l,m,lc);
	build(m,r,rc);
	up(x);
}
inline void update(int L,int R,int add,int l = 1,int r = n+1,int x = 1){
	push(x,l,r);
	if(l>=R || r<=L)return;
	if(l>=L && r<=R){
		lazy[x]+=add;
		push(x,l,r);
		return;
	}
	int m = (l+r)/2;
	update(L,R,add,l,m,lc);
	update(L,R,add,m,r,rc);
	up(x);
}
int L[N],R[N],vis[N],last;
VI spcl;
int solve(){
	int ret = INF;if(!last)return 0;
	for(auto i:spcl){
		for(int j=0;j<SZ(affect[i]);j++){
			int u = affect[i][j].S, val = min(miners[last],affect[i][j].F);
			int l = L[u], r = upper_bound(miners+1,miners+n+1,val)-miners;R[j]=r;
			update(l,r,1);if(ST[0][1]>=0)ret=min(ret,val-H[i]);
		}
		for(int j=0;j<SZ(affect[i]);j++){
			int u = affect[i][j].S;
			int l = L[u], r = R[j];
			update(l,r,-1);
		}
	}
	return ret;
}
void dfs(int u,int p){
	S.insert({H[u],u});
	auto it = S.begin();T[u]=it->F;it++;
	affect[S.begin()->S].PB({it->F,u});
	L[u] = upper_bound(miners+1,miners+n+1,T[u])-miners;
	update(0,L[u],1);
	for(auto w:g[u])
		if(w!=p)
			dfs(w,u);
	S.erase({H[u],u});
}
void bfs(int v){
	last = n;
	priority_queue<II> Q;
	Q.push({T[v],v});vis[v]=1;
	bool fucked = false;
	while(!Q.empty()){
		II top = Q.top();Q.pop();
		int u =top.S;
		if(top.F < miners[last])fucked=true;
		if(fucked){spcl.PB(u);continue;}
		last--;;
		for(auto w:g[u])
			if(!vis[w]){
				vis[w]=1;
				Q.push({T[w],w});
			}
	}
}
int main(){
	si(n);
	for(int i=1;i<=n;i++)si(H[i]);
	for(int i=1;i<n;i++){
		int u,v;
		si(u);si(v);
		g[u].PB(v);
		g[v].PB(u);
	}
	int k;si(k);
	for(int i=1;i<=k;i++)si(miners[i]);
	k = n;sort(miners+1,miners+n+1);
	for(int i=1;i<=n;i++)A[i]=-(n-i+1);
	S.insert({INF,1});build();dfs(1,1);
	for(int i=1;i<=n;i++)
		sort(ALL(affect[i]));
	bfs(1);
	int ans = solve();if(ans==INF)ans=-1;
	dout(ans);
	return 0;
}