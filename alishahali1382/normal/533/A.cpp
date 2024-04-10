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
const int MAXN = 500010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans=inf;
int A[MAXN], h[MAXN];
int seg[MAXN<<2], lazy[MAXN<<2];
pii mn[MAXN][2];
vector<int> G[MAXN], vec[MAXN], comp;

void add_lazy(int id, int val){
	seg[id]+=val;
	lazy[id]+=val;
}

void shift(int id){
	if (!lazy[id]) return ;
	add_lazy(id<<1, lazy[id]);
	add_lazy(id<<1 | 1, lazy[id]);
	lazy[id]=0;
}

void Add(int id, int tl, int tr, int l, int r, int val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		add_lazy(id, val);
		return ;
	}
	shift(id);
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
	seg[id]=min(seg[id<<1], seg[id<<1 | 1]);
}

void dfs(int node, int par){
	mn[node][0]=mn[par][0];
	mn[node][1]=mn[par][1];
	pii p={h[node], node};
	if (mn[node][0]>p) swap(mn[node][0], p);
	if (mn[node][1]>p) swap(mn[node][1], p);
	for (int v:G[node]) if (v!=par) dfs(v, node);
}

int Id(int x){
	return upper_bound(all(comp), x)-comp.begin();
}

void change(int v, int val){
	for (int u:vec[v]){
		Add(1, 0, MAXN, 0, Id(min(h[v], mn[u][1].first)), -1);
		Add(1, 0, MAXN, 0, Id(min(h[v]+val, mn[u][1].first)), +1);
	}
	h[v]+=val;
}

bool check(int v, int val){
	change(v, +val);
	int res=(seg[1]>=0);
	change(v, -val);
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>h[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	mn[0][0]=mn[0][1]={inf, 0};
	dfs(1, 0);
	for (int i=1; i<=n; i++) if (mn[i][0].first!=mn[i][1].first) vec[mn[i][0].second].pb(i);
	
	cin>>k;
	for (int i=1; i<=k; i++) cin>>A[i], comp.pb(A[i]);
	comp.pb(0);
	comp.pb(inf);
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
		
	for (int i=1; i<=n; i++){
		A[i]=Id(A[i]);
		Add(1, 0, MAXN, 0, A[i], -1);
		Add(1, 0, MAXN, 0, Id(mn[i][0].first), +1);
	}
	
	if (seg[1]>=0) kill(0)
	
	for (int i=1; i<=n; i++) A[i]=i;
	mt19937 mt_rand(time(0));
	shuffle(A+1, A+n+1, mt_rand);
	
	for (int j=1; j<=n; j++){
		int i=A[j];
		if (!check(i, ans-1)) continue ;		
		int dwn=0, up=ans-1;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			if (check(i, mid)) up=mid;
			else dwn=mid;
		}
		ans=up;
	}
	if (ans==inf) ans=-1;
	cout<<ans<<'\n';
	
	return 0;
}