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
const ll INF=1000000000000000010LL;
const int mod=1000000007;
const int N=1010, MAXN=N*N;

ll n, m, k, u, v, x, y, t, a, b, ans;
bool A[N][N];
int id[N][N], cnt;
pii id2[MAXN];
ll dist[MAXN];
int P[MAXN];
queue<int> Q;

int get(int x, int y, ll t){
	return (A[x][y]+t-dist[id[x][y]])%2;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>t;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		char ch;
		cin>>ch;
		A[i][j]=(ch=='1');
		id2[id[i][j]=cnt++]={i, j};
	}
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++){
		bool bad=1;
		if (1<i && A[i][j]==A[i-1][j]) bad=0;
		if (i<n && A[i][j]==A[i+1][j]) bad=0;
		if (1<j && A[i][j]==A[i][j-1]) bad=0;
		if (j<m && A[i][j]==A[i][j+1]) bad=0;
		if (!bad){
			P[id[i][j]]=id[i][j];
			Q.push(id[i][j]);
			continue ;
		}
		dist[id[i][j]]=INF;
	}
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		int x=id2[v].first, y=id2[v].second;
		if (1<x){
			int w=(A[x-1][y]!=get(x, y, dist[v]));
			int u=id[x-1][y];
			if (dist[u]>dist[v]+w){
				dist[u]=dist[v]+w;
				P[u]=P[v];
				Q.push(u);
			}
		}
		if (1<y){
			int w=(A[x][y-1]!=get(x, y, dist[v]));
			int u=id[x][y-1];
			if (dist[u]>dist[v]+w){
				dist[u]=dist[v]+w;
				P[u]=P[v];
				Q.push(u);
			}
		}
		if (x<n){
			int w=(A[x+1][y]!=get(x, y, dist[v]));
			int u=id[x+1][y];
			if (dist[u]>dist[v]+w){
				dist[u]=dist[v]+w;
				P[u]=P[v];
				Q.push(u);
			}
		}
		if (y<m){
			int w=(A[x][y+1]!=get(x, y, dist[v]));
			int u=id[x][y+1];
			if (dist[u]>dist[v]+w){
				dist[u]=dist[v]+w;
				P[u]=P[v];
				Q.push(u);
			}
		}
	}
	
	while (t--){
		cin>>x>>y>>k;
		if (k<=dist[id[x][y]]) cout<<A[x][y]<<'\n';
		else{
			cout<<(k-dist[id[x][y]]+A[x][y])%2<<'\n';
		}
	}
	
	return 0;
}