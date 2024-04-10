#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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

int n, m, k, u, v, x, y, t, a, b;
int A[MAXN];
int ans[MAXN];
int cnt[MAXN];
set<int> st[MAXN];
vector<int> D[MAXN];
vector<int> G[MAXN];

void change(int x, int delta){
	/*
	for (int d:D[x]){
		st[cnt[d]].erase(d);
		st[cnt[d]+=delta].insert(d);
	}*/
	for (int d:D[x]) cnt[d]+=delta;
}

void dfs(int node, int par, int h){
	change(A[node], 1);
	//ans[node]=max(*st[h].rbegin(), *st[h-1].rbegin());
	for (int d:D[A[1]]) if (cnt[d]>=h-1) ans[node]=max(ans[node], d);
	for (int d:D[A[node]]) if (cnt[d]>=h-1) ans[node]=max(ans[node], d);
	for (int v:G[node]) if (v!=par) dfs(v, node, h+1);
	change(A[node], -1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=1; i<MAXN; i++) for (int j=i; j<MAXN; j+=i) D[j].pb(i);
	//for (int i=1; i<MAXN; i++) st[0].insert(i), st[i].insert(1);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1, 1);
	ans[1]=A[1];
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
	
	return 0;
}