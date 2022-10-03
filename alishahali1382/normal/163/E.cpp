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
const int MAXN = 1000010, SGM=26;

int n, m, k, u, v, x, y, t, a, b;
string A[MAXN], S;
int fen[MAXN];
int stt[MAXN], fnt[MAXN], timer=1;
int id[MAXN], status[MAXN];
int F[MAXN];
int C[MAXN][SGM], ts;
vector<int> G[MAXN];
char typ;

void upd(int pos, int x){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;
}

void Add(int v, int val){
	upd(stt[v], val);
	upd(fnt[v], -val);
}

int Get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
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
		for (int i=0; i<SGM; i++){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				Q.push(C[v][i]);
				F[C[v][i]]=C[F[v]][i];
			}
		}
	}
}

void dfs(int node){
	stt[node]=timer++;
	for (int v:G[node]) dfs(v);
	fnt[node]=timer;
}

void BuildTree(){
	for (int i=1; i<=ts; i++) if (F[i]!=i) G[F[i]].pb(i);
	dfs(0);
	for (int i=1; i<=n; i++) Add(id[i], +1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>m>>n;
	for (int i=1; i<=n; i++) cin>>A[i], id[i]=AddTrie(A[i]), status[i]=1;
	BuildAho();
	BuildTree();
	
	while (m--){
		cin>>typ;
		if (typ=='?'){
			ll ans=0;
			cin>>S;
			int v=0;
			for (char ch:S) ans+=Get(stt[v=C[v][ch-'a']]);
			cout<<ans<<'\n';
			continue ;
		}
		int tmp=(typ=='+');
		cin>>x;
		Add(id[x], tmp-status[x]);
		status[x]=tmp;
	}
		
	return 0;
}