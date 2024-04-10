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
const int MAXN = 200010, SGM=26;

int n, m, k, u, v, x, y, t, l, r;
string S[MAXN];
int ans[500010];
int C[MAXN][SGM], ts;
int F[MAXN];
int fen[MAXN];
int id[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
vector<int> G[MAXN];
vector<pii> Q1[MAXN], Q2[MAXN];

void Add(int pos, int val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
}

int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

int Get(int v){
	return get(fnt[v]-1)-get(stt[v]-1);
}

int AddTrie(string &s){
	int node=0;
	for (char ch:s){
		if (!C[node][ch-'a']) C[node][ch-'a']=++ts;
		node=C[node][ch-'a'];
	}
	return node;
}

void BuildAho(){
	queue<int> Q;
	for (int i=0; i<SGM; i++) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		G[F[v]].pb(v);
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				F[C[v][i]]=C[F[v]][i];
				Q.push(C[v][i]);
			}
		}
	}
}

void dfs(int node){
	stt[node]=timer++;
	for (int v:G[node]) dfs(v);
	fnt[node]=timer;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>S[i];
	for (int i=1; i<=m; i++){
		cin>>l>>r>>k;
		Q1[l].pb({k, i});
		Q2[r].pb({k, i});
	}
	
	for (int i=1; i<=n; i++) id[i]=AddTrie(S[i]);
	BuildAho();
	dfs(0);
	
	for (int i=1; i<=n; i++){
		for (pii p:Q1[i]) ans[p.second]-=Get(id[p.first]);
		int v=0;
		for (char ch:S[i]){
			v=C[v][ch-'a'];
			Add(stt[v], +1);
		}
		for (pii p:Q2[i]) ans[p.second]+=Get(id[p.first]);
	}
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n'; 
	
	return 0;
}