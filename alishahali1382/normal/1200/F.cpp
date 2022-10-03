#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")

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
const int MAXN = 1010, M=9*8*7*5;

int n, m, q, u, v, x, y, t, a, b;
int K[MAXN];
int G[MAXN*M];
int deg[MAXN*M];
int ans[MAXN*M];
int E[MAXN][10];
bool mark[MAXN];
vector<int> vec;
queue<int> Q;

int fix(int x){
	x%=M;
	if (x<0) x+=M;
	return x;
}

int get(int v){
	if (ans[v]) return ans[v];
	return ans[v]=get(G[v]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>K[i], K[i]=fix(K[i]);
	for (int i=1; i<=n; i++){
		cin>>m;
		for (int j=0; j<m; j++) cin>>E[i][j];
		for (int j=0; j<M; j++) deg[G[M*i+j]=E[i][(j+K[i])%m]*M+fix(j+K[i])]++;
	}
	for (int i=1; i<=n; i++) for (int j=0; j<M; j++) if (!deg[i*M+j]) Q.push(i*M+j);
	while (!Q.empty()){
		int v=Q.front();
		Q.pop();
		if (!(--deg[G[v]])) Q.push(G[v]);
	}
	
	for (int i=1; i<=n; i++) for (int j=0; j<M; j++) if (deg[i*M+j] && !ans[i*M+j]){
		int node=i*M+j, v=node;
		while (1){
			vec.pb(v);
			if (!mark[v/M]){
				mark[v/M]=1;
				ans[node]++;
			}
			v=G[v];
			if (v==node) break ;
		}
		for (int v:vec) ans[v]=ans[node], mark[v/M]=0;
		vec.clear();
	}
	
	cin>>q;
	while (q--){
		cin>>x>>y;
		y=fix(y);
		cout<<get(x*M+y)<<'\n';
	}
	
	return 0;
}