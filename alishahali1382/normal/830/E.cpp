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
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int comp[MAXN];
int ans[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];

void SIK(){
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
}

bool dfs1(int node, int par){
	comp[node]=comp[par];
	bool res=0;
	for (int v:G[node]) if (v!=par){
		if (comp[v] || dfs1(v, node)) res=1;
	}
	return res;
}

bool dfs2(int node, int par){
	ans[node]=2;
	if (par && G[node].size()==3) return 1;
	for (int v:G[node]) if (v!=par && dfs2(v, node)) return 1;
	ans[node]=0;
	return 0;
}

void Solve(){
	cin>>n>>m;
	for (int i=1; i<=n; i++) G[i].clear(), comp[i]=ans[i]=0;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++){
		if (G[i].size()>=4){
			ans[i]=2;
			for (int j=0; j<4; j++) ans[G[i][j]]=1;
			SIK();
			return ;
		}
		if (!comp[i]){
			comp[0]=i;
			if (dfs1(i, 0)){
				for (int j=1; j<=n; j++) ans[j]=(comp[j]==i);
				SIK();
				return ;
			}
		}
	}
	for (int i=1; i<=n; i++) if (G[i].size()==3 && dfs2(i, 0)){
		for (int j=1; j<=n; j++) if (!ans[j] && comp[j]==comp[i]) ans[j]=1;
		SIK();
		return ;
	}
	for (int i=1; i<=n; i++) if (G[i].size()==3){
		vector<int> vec[3];
		for (int j=0; j<3; j++){
			vec[j]={i, G[i][j]};
			while (G[vec[j].back()].size()==2) vec[j].pb(G[vec[j].back()][0]^G[vec[j].back()][1]^vec[j][vec[j].size()-2]);
		}
		if (vec[0].size()>vec[1].size()) vec[0].swap(vec[1]);
		if (vec[0].size()>vec[2].size()) vec[0].swap(vec[2]);
		if (vec[1].size()>vec[2].size()) vec[1].swap(vec[2]);
//		debugv(vec[0])
//		debugv(vec[1])
//		debugv(vec[2])
		if (vec[0].size()>=3){
			ans[i]=3;
			ans[vec[0][1]]=2;
			ans[vec[0][2]]=1;
			ans[vec[1][1]]=2;
			ans[vec[1][2]]=1;
			ans[vec[2][1]]=2;
			ans[vec[2][2]]=1;
			SIK();
			return ;
		}
		if (vec[1].size()>=4){
			ans[i]=4;
			ans[vec[0][1]]=2;
			for (int shit:{1, 2}){
				ans[vec[shit][1]]=3;
				ans[vec[shit][2]]=2;
				ans[vec[shit][3]]=1;
			}
			SIK();
			return ;
		}
		if (vec[1].size()==3 && vec[2].size()>=6){
			ans[vec[0][1]]=3;
			ans[vec[1][1]]=4;
			ans[vec[1][2]]=2;
			for (int j=0; j<6; j++) ans[vec[2][j]]=6-j;
			SIK();
			return ;
		}
		// maybe more?
	}
	
	cout<<"NO\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Solve();
	
	return 0;
}