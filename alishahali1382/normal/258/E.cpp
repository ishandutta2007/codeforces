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

int n, m, k, u, v, x, y, t, a, b;
int stt[MAXN], fnt[MAXN], timer=1;
int ans[MAXN];
int seg[MAXN<<2], cnt[MAXN<<2];
vector<int> G[MAXN];
vector<int> vec[MAXN];

void dfs(int node, int par){
	stt[node]=timer++;
	for (int v:G[node]) if (v!=par) dfs(v, node);
	fnt[node]=timer;
}

void update(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id]+=val;
		if (seg[id]) cnt[id]=tr-tl;
		else{
			if (tr-tl==1) cnt[id]=0;
			else cnt[id]=cnt[id<<1] + cnt[id<<1 | 1];
		}
		return ;
	}
	int mid=(tl+tr)>>1;
	update(id<<1, tl, mid, l, r, val);
	update(id<<1 | 1, mid, tr, l, r, val);
	if (seg[id]) cnt[id]=tr-tl;
	else cnt[id]=cnt[id<<1] + cnt[id<<1 | 1];
}

void dfs2(int node, int par){
	for (int x:vec[node]) update(1, 1, n+1, stt[x], fnt[x], +1);
	update(1, 1, n+1, stt[node], stt[node]+1, +1);
	ans[node]=cnt[1]-1;
	update(1, 1, n+1, stt[node], stt[node]+1, -1);
	for (int v:G[node]) if (v!=par) dfs2(v, node);
	for (int x:vec[node]) update(1, 1, n+1, stt[x], fnt[x], -1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	
	while (m--){
		cin>>a>>b;
		vec[a].pb(a);
		vec[a].pb(b);
		vec[b].pb(a);
		vec[b].pb(b);
	}
	dfs2(1, 1);
	
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	
	return 0;
}