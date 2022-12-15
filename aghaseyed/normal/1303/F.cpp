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
const int mod = 1000000007;
const int MAXN=2000010;

int n, m, k, q, x, y, t, a, b, comp;
int C[MAXN], V[MAXN];
int par[MAXN], A[MAXN];
int ans[MAXN], P[MAXN];
int id[305][305], N;
pii id2[MAXN];
int bad[MAXN], tof[MAXN], koj[MAXN];

int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}

int join(int x, int y){
	x=get(x);
	y=get(y);
	par[x]=y;
	return x!=y;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) id2[id[i][j]=N++]={i, j};
	for (int i=1; i<=q; i++){
		cin>>x>>y>>C[i];
		V[i]=id[x][y];
		if (A[V[i]]==C[i]) P[i]=i-1;
		else A[V[i]]=C[i];
	}
	
	memset(A, 0, sizeof(A));
	
	for (int c=1; c<=C[q]; c++){
		int ql=lower_bound(C+1, C+q+1, c)-C, qr=upper_bound(C+1, C+q+1, c)-C;
		if (qr-ql<=0) continue ;
		for (int i=ql; i<qr; i++) bad[V[i]]=c;
		
		iota(par, par+N, 0);
		comp=n*m;
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (bad[id[i][j]]!=c){
			if (i-1 && A[id[i-1][j]]==A[id[i][j]] && bad[id[i-1][j]]!=c) comp-=join(id[i-1][j], id[i][j]);
			if (j-1 && A[id[i][j-1]]==A[id[i][j]] && bad[id[i][j-1]]!=c) comp-=join(id[i][j-1], id[i][j]);
		}
		for (int i=0; i<N; i++) tof[i]=par[i];
		int compp=comp;
		
		for (int i=ql; i<qr; i++) if (!P[i]) koj[V[i]]=i;
		for (int i=qr-1; i>=ql; i--) if (!P[i]){
			ans[i]=comp;
			int x=id2[V[i]].first, y=id2[V[i]].second, v=V[i];
			if (x-1 && A[id[x-1][y]]==A[v] && (bad[id[x-1][y]]!=c || koj[id[x-1][y]]>=i)) comp-=join(id[x-1][y], v);
			if (y-1 && A[id[x][y-1]]==A[v] && (bad[id[x][y-1]]!=c || koj[id[x][y-1]]>=i)) comp-=join(id[x][y-1], v);
			if (x+1<=n && A[id[x+1][y]]==A[v] && (bad[id[x+1][y]]!=c || koj[id[x+1][y]]>=i)) comp-=join(id[x+1][y], v);
			if (y+1<=m && A[id[x][y+1]]==A[v] && (bad[id[x][y+1]]!=c || koj[id[x][y+1]]>=i)) comp-=join(id[x][y+1], v);
		}
		
		
		for (int i=0; i<N; i++) par[i]=tof[i];
		comp=0;
		//for (int i=ql; i<qr; i++) if (!P[i]) comp++;
		
		for (int i=ql; i<qr; i++){
			int x=id2[V[i]].first, y=id2[V[i]].second, v=V[i];
			A[v]=c;
			if (x-1 && A[id[x-1][y]]==A[id[x][y]]) comp-=join(id[x-1][y], id[x][y]);
			if (y-1 && A[id[x][y-1]]==A[id[x][y]]) comp-=join(id[x][y-1], id[x][y]);
			if (x+1<=n && A[id[x+1][y]]==A[id[x][y]]) comp-=join(id[x+1][y], id[x][y]);
			if (y+1<=m && A[id[x][y+1]]==A[id[x][y]]) comp-=join(id[x][y+1], id[x][y]);
			
			
			ans[i]+=comp;
		}
		
		
		
	}
	
	
	for (int i=1; i<=q; i++){
		if (P[i]) ans[i]=ans[P[i]];
		cout<<ans[i]<<'\n';
	}
	
	return 0;
}