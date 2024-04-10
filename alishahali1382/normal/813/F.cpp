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

int n, m, k, u, v, x, y, t, a, b, res=1;
int X[MAXN], Y[MAXN], ans[MAXN];
int par[MAXN], col[MAXN], R[MAXN];
vector<pii> seg[MAXN<<2];
vector<pair<int*, int>> todo;
map<pii, int> mp;

pii Getpar(int x){
	if (par[x]==x) return {x, 0};
	pii p=Getpar(par[x]);
	return {p.first, p.second^col[x]};
}

int Join(int u, int v){
	//debug2(u, v)
	if (!res) return 0;
	int opp=0;
	pii x=Getpar(u);
	pii y=Getpar(v);
	if (x.first==y.first){
		if (x.second^y.second) return 0;
		res=0;
		return 0;
	}
	if (R[x.first]<R[y.first]) swap(x, y);
	if (1^x.second^y.second){
		todo.pb({&col[y.first], 0});
		opp++;
		col[y.first]=1;
	}
	todo.pb({&R[x.first], R[x.first]});
	opp++;
	R[x.first]+=R[y.first];
	
	todo.pb({&par[y.first], y.first});
	opp++;
	par[y.first]=x.first;
	
	return opp;
}

void Add(int id, int tl, int tr, int l, int r, pii E){
	if (r<=tl || tr<=l) return ;
	if (l<=tl && tr<=r){
		seg[id].pb(E);
		return ;
	}
	int mid=(tl+tr)>>1;
	Add(id<<1, tl, mid, l, r, E);
	Add(id<<1 | 1, mid, tr, l, r, E);
}

void dfs(int id, int tl, int tr){
	int rr=res, cnt=0;
	for (pii p:seg[id]) cnt+=Join(p.first, p.second);
	
	if (tr-tl==1) ans[tl]=res;
	else{
		int mid=(tl+tr)>>1;
		dfs(id<<1, tl, mid);
		dfs(id<<1 | 1, mid, tr);
	}
	
	res=rr;
	while (cnt--){
		auto it=todo.back();
		todo.pop_back();
		(*it.first)=it.second;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>X[i]>>Y[i];
		if (X[i]>Y[i]) swap(X[i], Y[i]);
		if (!mp.count({X[i], Y[i]})) mp[{X[i], Y[i]}]=i;
		else{
			Add(1, 1, m+1, mp[{X[i], Y[i]}], i, {X[i], Y[i]});
			mp.erase({X[i], Y[i]});
		}
	}
	for (auto it:mp) Add(1, 1, m+1, it.second, m+1, it.first); 
	for (int i=1; i<=n; i++) par[i]=i;
	dfs(1, 1, m+1);
	for (int i=1; i<=m; i++) cout<<(ans[i]?"YES":"NO")<<'\n';
	
	
	return 0;
}