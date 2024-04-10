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
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 20010, N=4001;
typedef array<int, N> knapsack;

int n, p, q, k, u, v, x, y, t, a, b, c, h;
int ans[MAXN];
knapsack dp[20];
vector<pii> seg[MAXN<<2], Q[MAXN];

void Add(int id, int tl, int tr, int l, int r, pii val){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(val);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, val);
	Add(id<<1 | 1, mid, tr, l, r, val);
}

void dfs(int id, int tl, int tr, int depth){
	for (pii p:seg[id]){
		int c=p.first, h=p.second;
		for (int i=N-1; i>=c; i--) dp[depth][i]=max(dp[depth][i], dp[depth][i-c] + h);
	}
	if (tr-tl==1){
		for (pii p:Q[tl]) ans[p.second]=dp[depth][p.first];
		return ;
	}
	int mid=(tl+tr)>>1;
	dp[depth+1]=dp[depth];
	dfs(id<<1, tl, mid, depth+1);
	dp[depth+1]=dp[depth];
	dfs(id<<1 | 1, mid, tr, depth+1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>p;
	while (n--){
		cin>>c>>h>>t;
		Add(1, 0, MAXN, t, t+p, {c, h});
	}
	cin>>q;
	for (int i=1; i<=q; i++){
		cin>>a>>b;
		Q[a].pb({b, i});
	}
	dfs(1, 0, MAXN, 0);
	for (int i=1; i<=q; i++) cout<<ans[i]<<'\n';
	
	return 0;
}