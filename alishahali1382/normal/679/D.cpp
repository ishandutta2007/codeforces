#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int N=410;

int n, m, k, u, v, x, y, t, a, b;
int G[N][N], deg[N];
ld cnt[N], mx[N];
bool mark[N];
vector<int> vec[N];

ld Get(vector<int> &vec){
	ld ans=0, tot=vec.size();
	for (int u=1; u<=n; u++) cnt[u]=0;
	for (int x:vec) for (int u=1; u<=n; u++) if (G[x][u]==1) cnt[u]+=1./deg[x];
	vector<int> good;
	for (int u=1; u<=n; u++) if (cnt[u]>0) good.pb(u);
	
//	debug(cnt[1])
//	debug(cnt[2])
//	debug(cnt[3])
//	debugv(vec)
//	debugv(good)
	
	for (int v=1; v<=n; v++){
		for (int x:good) mx[G[v][x]]=max(mx[G[v][x]], cnt[x]);
		ld res=0;
		for (int x:good){
			int d=G[v][x];
			res+=mx[d]/tot;
			mx[d]=0;
		}
		ans=max(ans, res);
		
//		debug2(v, res)
//		cerr<<'\n';
		
	}
//	debug(ans)
//	cerr<<"\n\n";
//	exit(0);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(G, 31, sizeof(G));
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		G[u][v]=G[v][u]=1;
		deg[u]++;
		deg[v]++;
	}
	for (int i=1; i<=n; i++) G[i][i]=0;
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				G[i][j]=min(G[i][j], G[i][k]+G[k][j]);
	
	ld ans=0;
	for (int v=1; v<=n; v++){
		for (int i=0; i<n; i++) vec[i].clear();
		for (int i=1; i<=n; i++) vec[G[v][i]].pb(i);
		ld res=0;
		for (int i=0; i<n; i++){
			if (vec[i].empty()) break ;
			memset(cnt, 0, sizeof(cnt));
			ld tmp=Get(vec[i]);
			tmp=max(tmp, (ld)1./vec[i].size());
			res+=vec[i].size()*tmp/n;
		}
		ans=max(ans, res);
//		debug2(v, res)
	}
	cout<<setprecision(10)<<fixed<<ans<<'\n';
	
	return 0;
}