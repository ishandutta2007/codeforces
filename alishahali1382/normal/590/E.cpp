#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 755, N=10000010, SGM=2;

int n, m, k, u, v, x, y, t, a, b, ans;
int C[N][SGM], F[N], ts;
int pos[MAXN], up[N];
int match[MAXN*2], dist[MAXN*2];
bool VC[MAXN], mark[MAXN], out[MAXN];
bool edge[MAXN][MAXN];
vector<int> G[MAXN];
string S[MAXN];
queue<int> Q;

int AddTrie(string &s){
	int v=0;
	for (char ch:s){
		if (!C[v][ch-'a']) C[v][ch-'a']=++ts;
		v=C[v][ch-'a'];
	}
	return v;
}

void BuildAho(){
	for (int i=0; i<SGM; i++) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		if (!up[v]) up[v]=up[F[v]];
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				F[C[v][i]]=C[F[v]][i];
				Q.push(C[v][i]);
			}
		}
	}
}

bool bfs(){
	memset(VC, 0, sizeof(VC));
	memset(dist, 31, sizeof(dist));
	for (int i=1; i<=n; i++) if (!match[i]){
		dist[i]=0;
		Q.push(i);
	}
	bool res=0;
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		if (v<=n){
			VC[v]=1;
			for (int u:G[v]) if (dist[v]+1<dist[u]){
				dist[u]=dist[v]+1;
				Q.push(u);
			}
			continue ;
		}
		if (!match[v]){
			res=1;
			continue ;
		}
		dist[match[v]]=dist[v]+1;
		Q.push(match[v]);
	}
	return res;
}

bool dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (!match[v] || dist[node]+1==dist[v] && !mark[match[v]] && dfs(match[v])){
		match[node]=v;
		match[v]=node;
		return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>S[i], up[pos[i]=AddTrie(S[i])]=i;
	BuildAho();
	
	for (int i=1; i<=n; i++){
		int v=0;
		for (char ch:S[i]){
			v=C[v][ch-'a'];
			for (int u=up[v]; u && !edge[u][i]; u=up[F[pos[u]]]) if (i!=u) {
				G[u].pb(i+n);
				edge[u][i]=1;
			}
		}
	}
		
	while (bfs()){
		memset(mark, 0, sizeof(mark));
		for (int i=1; i<=n; i++) if (!match[i] && !mark[i]) ans+=dfs(i);
	}
	
	for (int i=1; i<=n; i++) if (match[i]){
		if (VC[i]) out[match[i]-n]=1;
		else out[i]=1;
	}
	cout<<n-ans<<'\n';
	for (int i=1; i<=n; i++) if (!out[i]) cout<<i<<' ';
	
	return 0;
}