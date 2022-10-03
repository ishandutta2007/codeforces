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
#define SZ(x) ((int)x.size())
#define kill(x) return cout<<x<<'\n', 0;
#define getbit(x, y) (((x)>>(y))&1)

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=200010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], typ[MAXN];
int match[MAXN], mark[MAXN];
vector<int> G[MAXN];
vector<pii> E;

inline void add_edge(int u, int v){
	G[u<<1].pb(v<<1 | 1);
}
bool dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (match[v]==-1 || (!mark[match[v]] && dfs(match[v]))){
		match[v]=node;
		match[node]=v;
		return 1;
	}
	return 0;
}
int MaxMatch(){
	fill(match, match+4*n, -1);
	int res=0, flag=1;
	while (flag--){
		fill(mark, mark+4*n, 0);
		for (int i=0; i<4*n; i+=2)
			if (!mark[i] && match[i]==-1 && dfs(i)) res++, flag=1;
	}
	return res;
}

void Main(){
	E.clear();
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i], B[A[i]]=i, typ[i]=0;
	if (n<1000){
		sort(A, A+n);
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++)
			if (A[j]%A[i]==0) E.pb({i, j});
	}
	else{
		for (int i=0; i<n; i++){
			for (int j=2*A[i]; j<=50000; j+=A[i])
				if (B[j]!=-1) E.pb({i, B[j]});
		}
	}
	ans=0;
	for (int i=0; i<4*n; i++) G[i].clear();
	for (int i=0; i<n; i++) add_edge(i<<1, i<<1 | 1);
	for (pii p:E){
		int u=p.first, v=p.second;
//		debug2(u, v)
		add_edge(u<<1, v<<1);
		add_edge(u<<1, v<<1 | 1);
		add_edge(u<<1 | 1, v<<1 | 1);
	}
	
	ans=MaxMatch();
//	debug(ans)
	cout<<ans-n<<"\n";
	
	for (int i=0; i<n; i++) B[A[i]]=-1;
	
//	for (int i=0; i<4*n; i+=2) if (match[i]!=-1) debug2(i/2, match[i]/2)
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(B, -1, sizeof(B));
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
4
30 2 3 5

*/