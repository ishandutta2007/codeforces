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
const int MAXN = 1000010, LOG=20;

int n, m, k, u=2, v=3, x, y, t, a, b, ans=2;
int h[MAXN];
int par[MAXN][LOG];

int Lca(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	if (x==y) return x;
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]) x=par[x][i], y=par[y][i];
	return par[x][0];
}

int dist(int x, int y){
	return h[x]+h[y]-2*h[Lca(x, y)];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (n=1; n<=4; n++) for (int i=0; i<LOG; i++) par[n][i]=1;
	h[2]=h[3]=h[4]=1;
	n=4;
	cin>>m;
	while (m--){
		cin>>x;
		par[++n][0]=x;
		for (int i=1; i<LOG; i++) par[n][i]=par[par[n][i-1]][i-1];
		h[n]=h[x]+1;
		
		par[++n][0]=x;
		for (int i=1; i<LOG; i++) par[n][i]=par[par[n][i-1]][i-1];
		h[n]=h[x]+1;
		
		int tmp=dist(u, n);
		if (tmp>ans){
			ans=tmp;
			v=n;
		}
		
		tmp=dist(v, n);
		if (tmp>ans){
			ans=tmp;
			u=n;
		}
		
		cout<<ans<<'\n';
	}
	
	
	return 0;
}