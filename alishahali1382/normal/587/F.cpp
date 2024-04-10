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
const int MAXN = 100010, SGM=26, SQ=320;

int n, m, k, u, v, x, y, t, l, r;
string S[MAXN];
int F[MAXN];
int C[MAXN][SGM], ts;
int stt[MAXN], fnt[MAXN], timer=1;
int id[MAXN];
//int fen[MAXN];
int A[MAXN], lazy[SQ];
ll ans[MAXN], ps[MAXN];
int cnt[MAXN];
vector<pii> Q1[MAXN], Q2[MAXN];
vector<piii> Q3[MAXN];
vector<int> G[MAXN];

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

void Add(int l, int r, int val=1){
	/*
	for (int pos=l; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
	for (int pos=r; pos<MAXN; pos+=pos&-pos) fen[pos]-=val;
	*/
	while (l<r){
		if (l%SQ==0 && l+SQ<=r){
			lazy[l/SQ]+=val;
			l+=SQ;
		}
		else{
			A[l]+=val;
			l++;
		}
	}
}

int Get(int pos){
	/*
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
	*/
	return lazy[pos/SQ] + A[pos];
}

int dfs2(int node){
	for (int v:G[node]) cnt[node]+=dfs2(v);
	return cnt[node];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>S[i], id[i]=AddTrie(S[i]);
	BuildAho();
	dfs1(0);
	for (int i=1; i<=m; i++){
		cin>>l>>r>>k;
		if (S[k].size()<=SQ){
			Q1[l].pb({k, i});
			Q2[r].pb({k, i});
			continue ;
		}
		Q3[k].pb({{l, r}, i});
	}
			
	for (int i=1; i<=n; i++){
		for (pii p:Q1[i]){
			int v=0;
			for (char ch:S[p.first]){
				v=C[v][ch-'a'];
				ans[p.second]-=Get(stt[v]);
			}
		}
		
		Add(stt[id[i]], fnt[id[i]]);
		
		for (pii p:Q2[i]){
			int v=0;
			for (char ch:S[p.first]){
				v=C[v][ch-'a'];
				ans[p.second]+=Get(stt[v]);
			}
		}
	}
	
	for (int i=1; i<=n; i++) if (Q3[i].size()){
		memset(cnt, 0, sizeof(cnt));
		int v=0;
		for (char ch:S[i]){
			v=C[v][ch-'a'];
			cnt[v]++;
		}
		dfs2(0);
		for (int j=1; j<=n; j++) ps[j]=ps[j-1] + cnt[id[j]];
		for (piii p:Q3[i]) ans[p.second]=ps[p.first.second]-ps[p.first.first-1];
	}
	
	
	for (int i=1; i<=m; i++) cout<<ans[i]<<'\n';
	
	return 0;
}