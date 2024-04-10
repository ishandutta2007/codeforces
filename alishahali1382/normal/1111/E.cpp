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
const int MAXN = 100010, LOG=20;

int n, q, m, k, u, v, x, y, t, a, b, root;
int stt[MAXN], fnt[MAXN], timer=1;
int fen[MAXN];
int cnt[MAXN], A[MAXN];
ll dp[310];
vector<int> G[MAXN];
vector<pii> child[MAXN];

void upd(int pos, int val){ for (; pos<MAXN; pos+=pos&-pos) fen[pos]+=val;}
int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

void dfs(int node, int par){
	stt[node]=timer++;
	for (int v:G[node]) if (v!=par){
		dfs(v, node);
		child[node].pb({fnt[v], v});
	}
	fnt[node]=timer;
}

void Add(int v, int tmp=1){
	if (v==root){
		upd(1, tmp);
		//upd(n+1, -tmp);
		return ;
	}
	if (stt[v]<=stt[root] && fnt[root]<=fnt[v]){
		int u=lower_bound(all(child[v]), pii(fnt[root], 0))->second;
		//debug2(v, u)
		upd(1, tmp);
		upd(stt[u], -tmp);
		upd(fnt[u], +tmp);
		//upd(n+1, -tmp);
		return ;
	}
	upd(stt[v], +tmp);
	upd(fnt[v], -tmp);
}

bool cmp(int i, int j){ return cnt[i]<cnt[j];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>q;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	//debug("dfs done")
	while (q--){
		cin>>k>>m>>root;
		for (int i=1; i<=k; i++) cin>>A[i], Add(A[i], 1);
		for (int i=1; i<=k; i++) cnt[A[i]]=get(stt[A[i]])-1;
		for (int i=1; i<=k; i++) Add(A[i], -1);
		sort(A+1, A+k+1, cmp);
		//for (int i=1; i<=k; i++) debug2(A[i], cnt[A[i]])
		memset(dp, 0, sizeof(dp));
		dp[1]=1;
		for (int i=2; i<=k; i++) for (int j=m; j; j--) dp[j]=(dp[j-1] + dp[j]*(j-cnt[A[i]]))%mod;
		ll ans=0;
		for (int i=1; i<=m; i++) ans+=dp[i];
		cout<<ans%mod<<'\n';
	}
	
	
	return 0;
}
/*
10 1
4 3
5 2
4 8
6 9
2 4
1 2
1 9
9 10
7 5
2 2 10 9 6

*/