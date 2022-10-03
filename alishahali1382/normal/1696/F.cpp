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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int N=105;

int n, m, k, u, v, x, y, t, a, b, ans;
bool A[N][N][N], B[N][N][N]; // B is backup
int ted[N][N], mark[N][N];
int dist[N][N];
int dead[N];
int cnt[N];
pii mark2[N];
vector<int> G[N];
vector<pii> E;

void remove_vertex(int v){
	dead[v]=1;
	for (int x=1; x<=n; x++) for (int y=1; y<=n; y++) if (x^y){
		ted[x][y]-=(A[x][y][v]==1);
		A[x][y][v]=0;
	}
}
int get_middle_vertex(int x, int y){
	if (ted[x][y]!=1) return -1;
	if (mark[x][y]) return mark[x][y];
	for (int v=1; v<=n; v++) if (!dead[v] && A[x][y][v]) return mark[x][y]=v;
	return -1;
}
void add_edge(int x, int y){
	E.pb({x, y});
	G[x].pb(y);
	G[y].pb(x);
}
bool test_deg2_leaf(int v, int x){
	for (int y=1; y<=n; y++) if (!dead[y] && A[v][y][x]) return 0;
	return 1;
}

bool solve(){
	vector<int> alive;
	for (int i=1; i<=n; i++) if (!dead[i]) alive.pb(i);
	if (SZ(alive)==1) return 1;
	if (SZ(alive)==2){
		int x=alive[0], y=alive[1];
		add_edge(x, y);
		return A[x][y][x]==0 && A[x][y][y]==0;
	}
	
	for (int i=1; i<=n; i++) cnt[i]=0;
	for (int x=1; x<=n; x++) if (!dead[x]){
		for (int y=x+1; y<=n; y++) if (!dead[y]){
			if (ted[x][y]==1){
				int v=get_middle_vertex(x, y);
				cnt[v]++;
				mark2[v]={x, y};
			}
		}
	}
	vector<int> deg2;
	for (int i=1; i<=n; i++) if (!dead[i] && cnt[i]) deg2.pb(i);
	
	if (SZ(alive)==3){
		if (SZ(deg2)!=1) return 0;
		int v=deg2[0];
		if (cnt[v]>1) return 0;
		int x=mark2[v].first, y=mark2[v].second;
		if (x==v || y==v || x==y) return 0;
		add_edge(x, v);
		add_edge(y, v);
		return 1;
	}
	// SZ(alive)>=4
	int v=-1;
	for (int u:deg2) if (cnt[u]==1) v=u;
	if (v!=-1){
		// x--v--y
		// x or y is leaf
		int x=mark2[v].first, y=mark2[v].second;
//		cerr<<"found deg2 vertex "<<v<<" adjacent with "<<x<<", "<<y<<"\n";
		bool fx=test_deg2_leaf(v, x);
		bool fy=test_deg2_leaf(v, y);
		if (fx==fy) return 0;
		if (fy) swap(x, y);
//		cerr<<"vertex "<<x<<" is a leaf\n";
//		dead[x]=dead[v]=1;
		remove_vertex(x);
		remove_vertex(v);
		solve();
		add_edge(v, y);
		add_edge(x, v);
		return 1;
	}
	
	// every leaf has a brother
	int x=-1, y=-1;
	for (int xx=1; xx<=n && x==-1; xx++) if (!dead[xx]){
		for (int yy=1; yy<=n && x==-1; yy++) if (!dead[yy]){
			if (ted[xx][yy]==SZ(alive)-2){
				x=xx;
				y=yy;
			}
		}
	}
	if (x==-1) return 0; // its ok isnt it?!
//	cerr<<"found brothers "<<x<<" "<<y<<"\n";
	remove_vertex(y);
	solve();
	if (SZ(G[x])!=1) return 0;
	add_edge(y, G[x][0]);
	return 1;
}
void dfs(int v, int par, int *dist){
	for (int u:G[v]) if (u!=par){
		dist[u]=dist[v]+1;
		dfs(u, v, dist);
	}
}
bool check(){
	if (SZ(E)!=n-1) return 0;
	for (int i=1; i<=n; i++) dfs(i, i, dist[i]);
	for (int x=1; x<=n; x++) for (int y=x+1; y<=n; y++){
//		debug2(x, y)
		for (int z=1; z<=n; z++){
			bool f=(dist[x][z]==dist[y][z]);
//			debug(z)
			if (B[x][y][z]!=f) return 0;
		}
	}
	return 1;
}

int Main(){
	cin>>n;
	for (int x=1; x<=n; x++){
		for (int y=x+1; y<=n; y++){
			string S;
			cin>>S;
			for (int z=1; z<=n; z++)
				A[x][y][z]=A[y][x][z]=(S[z-1]-'0');
		}
	}
	for (int x=1; x<=n; x++){
		for (int y=x+1; y<=n; y++){
			if (A[x][y][x] || A[x][y][y]) kill("NO")
		}
	}
	
	memcpy(B, A, sizeof(B));
	for (int i=1; i<=n; i++){
		dead[i]=0;
		G[i].clear();
	}
	E.clear();
	for (int x=1; x<=n; x++) for (int y=1; y<=n; y++) if (x^y){
		ted[x][y]=0;
		mark[x][y]=0;
		for (int z=1; z<=n; z++) if (A[x][y][z]) ted[x][y]++;
	}
	
	bool res=solve();
	if (!res || !check()) kill("NO");
	cout<<"YES\n";
	for (pii p:E) cout<<p.first<<" "<<p.second<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
5
2
00
2
10
3
001 000
000
3
001 010
000
5
00000 01001 00000 01100
00000 10000 00000
00000 11010
00000

1
5
00000 01001 00000 01100
00000 10000 00000
00000 11010
00000

*/