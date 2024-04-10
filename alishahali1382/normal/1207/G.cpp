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
const int MAXN = 400010, SGM=26;

int n, m, k, u, v, x, y, t, a, b;
int C[MAXN][SGM], F[MAXN], ts;
int stt[MAXN], fnt[MAXN], timer=1;
int id[MAXN];
int fen[MAXN];
int ans[MAXN];
string T[MAXN];
vector<int> G[MAXN], Q[MAXN];
vector<pii> S[MAXN];

void add(int pos, int val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
}

int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

int AddAho(string &s){
	int node=0;
	for (char ch:s){
		if (!C[node][ch-'a']) C[node][ch-'a']=++ts;
		node=C[node][ch-'a'];
	}
	return node;
}

void BuildAhoJurassic(){
	queue<int> Q;
	for (int i=0; i<SGM; i++) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		G[F[v]].pb(v);
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				Q.push(C[v][i]);
				F[C[v][i]]=C[F[v]][i];
			}
		}
	}
}

void dfs1(int node){
	stt[node]=timer++;
	for (int v:G[node]) dfs1(v);
	fnt[node]=timer;
}

void dfs2(int node, int curr){
	for (int i:Q[node]) ans[i]=get(fnt[id[i]]-1)-get(stt[id[i]]-1);
	for (pii p:S[node]){
		int v=p.first, c=p.second;
		add(stt[C[curr][c]], +1);
		dfs2(v, C[curr][c]);
		add(stt[C[curr][c]], -1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>x;
		if (--x) cin>>x;
		char ch;
		cin>>ch;
		S[x].pb({i, ch-'a'});
	}
	cin>>m;
	for (int i=1; i<=m; i++){
		cin>>x>>T[i];
		id[i]=AddAho(T[i]);
		Q[x].pb(i);
	}
	BuildAhoJurassic();
	dfs1(0);
	dfs2(0, 0);
	
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}