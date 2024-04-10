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

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=1010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
int E[MAXN*5][2];
int dist[MAXN];
bool mark1[MAXN], mark2[MAXN];
vector<int> G[MAXN];

inline bool relax(int u, int v, int w){
	if (dist[u]+w<dist[v]){
		dist[v]=dist[u]+w;
		return 1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>E[i][0]>>E[i][1];
		G[E[i][0]].pb(E[i][1]);
	}
	mark1[1]=mark2[n]=1;
	for (int i=1; i<=n; i++) for (int v:G[i]) mark1[v]|=mark1[i];
	for (int i=n; i; i--) for (int v:G[i]) mark2[i]|=mark2[v];
	
	memset(dist, 31, sizeof(dist));
	dist[1]=0;
	for (int _=1; _<=n; _++){
		for (int i=0; i<m; i++){
			int u=E[i][0], v=E[i][1];
			if (!mark1[u] || !mark2[v]) continue ;
			if ((relax(u, v, 2) | relax(v, u, -1))){
				if (_==n) kill("No")
			}
		}
	}
	cout<<"Yes\n";
	for (int i=0; i<m; i++){
		if (dist[E[i][1]]-dist[E[i][0]]==2) cout<<"2\n";
		else cout<<"1\n";
	}
	
	return 0;
}