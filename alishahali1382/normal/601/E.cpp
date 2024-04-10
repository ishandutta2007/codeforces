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
const int P=1e7+19, Q=1e9+7;
const int MAXN = 30010, K=1001;

int n, q, k, u, v, x, y, t, a, b, ans;
int T[MAXN];
pii A[MAXN];
int B[MAXN];
bool dead[MAXN];
int dp[K];
vector<pii> seg[MAXN<<2];

void Add(int id, int tl, int tr, int l, int r, pii p){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(p);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, p);
	Add(id<<1 | 1, mid, tr, l, r, p);
}

void add(int w, int v){
	for (int i=k; i>=v; i--) dp[i]=max(dp[i], dp[i-v]+w);
}

void print(){
	ll res=0;
	for (int m=k; m; m--) res=(res*P+dp[m])%Q;
	cout<<res<<'\n';
	//for (int i=1; i<=k; i++) cerr<<dp[i]<<" \n"[i==k];
}

void dfs(int id, int tl, int tr){
	int dpp[K];
	memcpy(dpp, dp, sizeof(dp));
	for (pii p:seg[id]) add(p.first, p.second);
	
	if (tr-tl==1){
		if (T[tl]==3) print();
	}
	else{
		int mid=(tl+tr)>>1;
		dfs(id<<1, tl, mid);
		dfs(id<<1 | 1, mid, tr);
	}
	
	memcpy(dp, dpp, sizeof(dp));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>A[i].first>>A[i].second;
	cin>>q;
	for (int i=1; i<=q; i++){
		cin>>T[i];
		if (T[i]==1){
			n++;
			cin>>A[n].first>>A[n].second;
			B[n]=i;
			continue ;
		}
		if (T[i]==2){
			cin>>x;
			Add(1, 0, q+1, B[x], i, A[x]);
			dead[x]=1;
		}
	}
	for (int i=1; i<=n; i++) if (!dead[i]) Add(1, 0, q+1, B[i], q+1, A[i]);
	dfs(1, 0, q+1);
	
	return 0;
}