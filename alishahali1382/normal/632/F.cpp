#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef pair<int, int> pii;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const int MAXN = 2510;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN][MAXN];
int par[MAXN];
vector<pii> edge;
vector<int> vec[MAXN];

int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}	

int join(int x, int y, int w){
	x=get(x);
	y=get(y);
	if (x==y) return 0;
	if (vec[x].size()<vec[y].size()) swap(x, y);
	for (int i:vec[x]) for (int j:vec[y]) if (A[i][j]!=w){
		cout<<"NOT MAGIC\n";
		exit(0);
	}
	for (int i:vec[y]) vec[x].pb(i);
	vec[y].clear();
	par[y]=x;
	return 1;
}

bool cmp(pii i, pii j){ return A[i.first][i.second]<A[j.first][j.second];}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for (int i=1; i<MAXN; i++) par[i]=i, vec[i].pb(i);
	cin>>n;
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cin>>A[i][j];
	for (int i=1; i<=n; i++) if (A[i][i]) kill("NOT MAGIC")
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++){
		if (A[i][j]!=A[j][i]) kill("NOT MAGIC")
		edge.pb({i, j});
	}
	sort(edge.begin(), edge.end(), cmp);
	for (pii p:edge) join(p.first, p.second, A[p.first][p.second]);
	kill("MAGIC")
	
	return 0;
}