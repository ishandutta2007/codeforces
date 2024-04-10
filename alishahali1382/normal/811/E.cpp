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
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, N=10;

struct DSU{
	int par[MAXN*N];
	void build(int l, int r){
		iota(par+l, par+r, l);
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	int join(int x, int y, bool f){ // f=0 : left    f=1 : right
		x=get(x);
		y=get(y);
		if ((x>y)^f) swap(x, y);
		par[x]=y;
		return x!=y;
	}
} dsu1, dsu2;

int n, m, q, u, v, x, y, t, a, b;
int A[N][MAXN];
int ans[MAXN];
int shit[MAXN][N];
vector<pii> Q1[MAXN], Q2[MAXN];

void divide(int tl, int tr){
	if (tr-tl==1) return ;
	int mid=(tl+tr)>>1;
	divide(tl, mid);
	divide(mid, tr);
	dsu1.build(tl*n, mid*n);
	dsu2.build(mid*n, tr*n);
	int cnt=0;
	for (int i=mid; i<tr; i++){
		for (int j=1; j<n; j++) if (A[j][i]==A[j-1][i]) cnt+=dsu2.join(i*n+j-1, i*n+j, 1);
		if (i!=mid){
			for (int j=0; j<n; j++) if (A[j][i]==A[j][i-1]) cnt+=dsu2.join(i*n+j, (i-1)*n+j, 1);
		}
		for (pii p:Q2[i]) if (p.first<mid && tl<=p.first){
			//debug(cnt)
			ans[p.second]-=cnt;
			for (int j=0; j<n; j++) shit[p.second][j]=dsu2.get(mid*n+j);
		}
	}
	//debug(dsu1.par[n])
	//debug(dsu1.par[n+1])
	cnt=0;
	for (int i=mid-1; i>=tl; i--){
		//debug(i)
		for (int j=1; j<n; j++){
			//debug2(A[j][i], A[j-1][i])
			if (A[j][i]==A[j-1][i]) cnt+=dsu1.join(i*n+j-1, i*n+j, 0);
		}
		if (i!=mid-1){
			for (int j=0; j<n; j++) if (A[j][i]==A[j][i+1]) cnt+=dsu1.join(i*n+j, (i+1)*n+j, 0);
		}
		for (pii p:Q1[i]) if (mid<=p.first && p.first<tr){
			//debug(cnt)
			ans[p.second]-=cnt;
			for (int j=0; j<n; j++) dsu2.par[mid*n+j]=shit[p.second][j];
			for (int j=0; j<n; j++) dsu2.par[(mid-1)*n+j]=dsu1.get((mid-1)*n+j);
			for (int j=0; j<n; j++) if (A[j][mid-1]==A[j][mid]) ans[p.second]-=dsu2.join((mid-1)*n+j, mid*n+j, 0);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int j=0; j<n; j++) for (int i=1; i<=m; i++) cin>>A[j][i];
	//debug2(A[0][1], A[1][1])
	for (int i=1; i<=q; i++){
		cin>>x>>y;
		if (x==y){
			for (int j=0; j<n; j++) ans[i]+=(j==0 || A[j][x]!=A[j-1][x]);
			continue ;
		}
		ans[i]=(y-x+1)*n;
		Q1[x].pb({y, i});
		Q2[y].pb({x, i});
	}
	divide(1, m+1);
	for (int i=1; i<=q; i++) cout<<ans[i]<<'\n';
	
	return 0;
}
/*
4 5 1
1 1 1 1 1
1 2 2 3 3
1 1 1 2 5
4 4 5 5 5
1 5


4 2 1
1 1
1 2
1 1
4 4
1 2

ans : 3

*/