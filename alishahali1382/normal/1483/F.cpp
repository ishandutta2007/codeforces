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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=1000010, SGM=26;

int n, m, k, u, v, x, y, t, a, b, ans;
int C[MAXN][SGM], F[MAXN], ts;
int ID[MAXN], tah[MAXN], UP[MAXN];
int Q[MAXN], QL, QR;
int fen[MAXN];
int cnt[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
string S[MAXN];
vector<piii> vec;
vector<int> G[MAXN];

int AddTrie(string &s){
	int v=0;
	for (char ch:s){
		if (!C[v][ch-'a']) C[v][ch-'a']=++ts;
		v=C[v][ch-'a'];
	}
	return v;
}
void BuildAho(){
	for (int i=0; i<SGM; i++) if (C[0][i]) Q[QR++]=C[0][i];
	while (QL<QR){
		int v=Q[QL++];
		if (ID[v]) UP[v]=v;
		else UP[v]=UP[F[v]];
		G[F[v]].pb(v);
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				Q[QR++]=C[v][i];
				F[C[v][i]]=C[F[v]][i];
			}
		}
	}
}
void add(int pos, int val){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;
}
int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
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
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>S[i];
		tah[i]=AddTrie(S[i]);
		ID[tah[i]]=i;
//		debug2(i, tah[i])
	}
	BuildAho();
	dfs(0);
//	for (int i=1; i<=ts; i++) debug2(i, F[i])
	for (int i=1; i<=n; i++){
		vec.clear();
		int v=0;
		for (int j=0; j<SZ(S[i]); j++){
			int c=S[i][j]-'a';
			v=C[v][c];
			add(stt[v], +1);
			if (j+1==SZ(S[i])) v=F[v];
//			debug2(j, v)
			int id=ID[UP[v]];
//			debug(id)
//			cerr<<"\n";
			if (!id) continue ;
//			debug2(j, id)
			int r=j+1, l=r-SZ(S[id]);
			while (vec.size() && l<=vec.back().first.first) vec.pop_back();
			vec.pb({{l, r}, id});
		}
		for (auto p:vec) cnt[p.second]++;
		for (auto p:vec) if (cnt[p.second]){
			int v=tah[p.second];
			if (get(fnt[v]-1)-get(stt[v]-1)==cnt[p.second]){
//				debug2(p.second, i)
				ans++;
			}
			cnt[p.second]=0;
		}
		v=0;
		for (int j=0; j<SZ(S[i]); j++){
			int c=S[i][j]-'a';
			v=C[v][c];
			add(stt[v], -1);
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}
/*
2
ab
b

*/