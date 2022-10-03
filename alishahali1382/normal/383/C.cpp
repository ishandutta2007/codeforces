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
const int MAXN = 200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
int h[MAXN], stt[MAXN], fnt[MAXN], timer=1;
int fen[MAXN];
vector<int> G[MAXN];

void upd(int pos, int x){ for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=x;}
int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

void Add(int l, int r, int val){
	upd(l, +val);
	upd(r, -val);
}

void dfs(int node, int par){
	stt[node]=timer++;
	h[node]=-h[par];
	for (int v:G[node]) if (v!=par) dfs(v, node);
	fnt[node]=timer;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	h[1]=1;
	dfs(1, 1);
	//for (int i=1; i<=n; i++) debug2(stt[i], fnt[i])
	for (int i=1; i<=n; i++) Add(stt[i], stt[i]+1, h[i]*A[i]);
	while (m--){
		cin>>t>>v;
		if (t==2) cout<<h[v]*get(stt[v])<<'\n';
		else{
			cin>>x;
			Add(stt[v], fnt[v], h[v]*x);
		}
	}
	
	return 0;
}