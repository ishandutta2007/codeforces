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

const int inf=1000000010;
const ll INF=1000000000000001000LL;
const int mod=1000000007;
const int MAXN=2010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN], mark[MAXN];
int sum[MAXN], par[MAXN], good[MAXN];
vector<int> G[MAXN];

bool dfs(int node){
	mark[node]=1;
	bool res=0;
	for (int v:G[node]) if (v!=par[node] && sum[node]>A[v]){
		if (mark[v]){
			res=1;
			good[node]=good[v]=1;
		}
		else if (sum[node]>A[v]){
			sum[v]=min(B[v]+sum[node], inf);
			par[v]=node;
			res|=dfs(v);
		}
	}
	return res;
}

bool Solve(int val){
	memset(mark, 0, sizeof(mark));
	mark[1]=2;
	int flag=1;
	while (flag--){
		for (int i=1; i<=n; i++) if (mark[i]!=2) mark[i]=good[i]=0;
		for (int i=1; i<=n; i++) if (mark[i]==2){
			for (int v:G[i]) if (!mark[v] && val>A[v]){
				sum[v]=B[v]+val;
				par[v]=i;
				if (sum[v]>=inf) return 1;
				flag|=dfs(v);
			}
		}
		for (int i=1; i<=n; i++) if (good[i]){
			int v=i;
			while (mark[v]!=2){
				mark[v]=2;
				val+=B[v];
				if (val>=inf) return 1;
				v=par[v];
			}
		}
	}
	for (int i=1; i<=n; i++) if (mark[i]!=2) return 0;
	return 1;
}

void Main(){
	cin>>n>>m;
	for (int i=2; i<=n; i++) cin>>A[i];
	for (int i=2; i<=n; i++) cin>>B[i];
	for (int i=1; i<=n; i++) G[i].clear();
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int dwn=1, up=inf;
	while (up-dwn>1){
		int mid=(dwn+up)>>1;
		if (Solve(mid)) up=mid;
		else dwn=mid;
	}
	cout<<up<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	while (T--) Main();
	
	return 0;
}
/*
1
4 4
11 22 13
5 7 8
1 2
2 3
3 4
4 1

1
5 7
10 40 20 30
7 2 10 5
1 2
1 5
2 3
2 4
2 5
3 4
4 5

*/