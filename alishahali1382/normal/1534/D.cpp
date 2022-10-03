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
#define kill(x) return cout<<x<<'\n', 0;

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN][MAXN];
bool mark[MAXN], dead[MAXN];
vector<pii> E;

void ask(int v){
	if (mark[v]) return ;
	mark[v]=1;
	cout<<"? "<<v<<endl;
	for (int i=1; i<=n; i++) cin>>A[v][i];
}

void dfs(int v){
	dead[v]=1;
	vector<int> vec;
	for (int i=1; i<=n; i++) if (!dead[i] && A[v][i]==1) vec.pb(i);
	if (vec.empty()) return ;
	if (vec.size()==1){
		int u=vec[0];
		mark[u]=1;
		for (int i=1; i<=n; i++) A[u][i]=A[v][i]-1;
		dfs(u);
		return ;
	}
	int u=vec.back();
	ask(u);
	dfs(u);
	
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	ask(1);
	vector<int> X, Y;
	for (int i=2; i<=n; i++){
		if (A[1][i]&1) X.pb(i);
		else Y.pb(i);
	}
	if (X.size()>Y.size()) swap(X, Y);
	for (int v:X) ask(v);
	for (int i=1; i<=n; i++) if (mark[i]){
		for (int j=1; j<=n; j++) if (A[i][j]==1) E.pb({i, j});
	}
	for (pii &p:E) if (p.first>p.second) swap(p.first, p.second);
	sort(all(E));
	E.resize(unique(all(E))-E.begin());
	cout<<"!"<<endl;
	for (pii p:E) cout<<p.first<<" "<<p.second<<endl;
	
	return 0;
}