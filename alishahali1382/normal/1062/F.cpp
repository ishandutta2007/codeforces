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
const int MAXN=300010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int P[MAXN];
bool mark[MAXN];
int L[MAXN], R[MAXN];
ll ps1[MAXN], ps2[MAXN];
vector<int> topol, G[MAXN], GR[MAXN];

void dfs(int node){
	mark[node]=1;
	for (int v:G[node]) if (!mark[v]) dfs(v);
	topol.pb(node);
}

bool cmp(int x, int y){
	return P[x]<P[y];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		GR[v].pb(u);
	}
	for (int i=1; i<=n; i++) if (!mark[i]) dfs(i);
	topol.pb(0);
	reverse(all(topol));
	for (int i=1; i<=n; i++) P[topol[i]]=i, R[i]=n+1;
	
	//debugv(topol)
	
	for (int v=1; v<=n; v++){
		sort(all(G[v]), cmp);
		sort(all(GR[v]), cmp);
		int l=0, r=n+1;
		if (GR[v].size()) l=P[GR[v].back()];
		if (G[v].size()) r=P[G[v][0]];
		ps1[l+1]++;
		ps1[r]--;
		ps2[l+1]+=v;
		ps2[r]-=v;
		//cerr<<v<<" : "<<l<<' '<<r<<endl;
		//debug2(v, P[v])
		
		if (G[v].size()){
			int tmp=n+1;
			if (G[v].size()>1) tmp=P[G[v][1]];
			L[G[v][0]]=max(L[G[v][0]], tmp);
		}
		if (GR[v].size()){
			int tmp=0;
			if (GR[v].size()>1) tmp=P[GR[v][GR[v].size()-2]];
			//debug2(v, tmp)
			R[GR[v].back()]=min(R[GR[v].back()], tmp);
		}
	}
	for (int i=1; i<=n; i++) ps1[i]+=ps1[i-1], ps2[i]+=ps2[i-1];
	for (int v=1; v<=n; v++) ps1[v]--, ps2[P[v]]-=v;
	//debug(R[5])
	for (int v=1; v<=n; v++) if (ps1[P[v]]<=1){
		//debug(v)
		//debug2(ps1[P[v]], ps2[P[v]])
		if (!ps1[P[v]]){
			ans++;
			continue ;
		}
		int bad=ps2[P[v]];
		if (P[bad]<P[v]){
			if (L[bad]<=P[v]) ans++;
			continue ;
		}
		if (P[v]<=R[bad]) ans++;
		continue ;
	}
	cout<<ans<<'\n';
	
	return 0;
}