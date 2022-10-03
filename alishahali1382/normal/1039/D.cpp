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
const int MAXN = 100010, SQ=1304;

int n, m, k, u, v, x, y, t, a, b, ans;
int res[MAXN], val[MAXN];
int tof[MAXN], timer=1;
int A[MAXN];
vector<int> G[MAXN];

void Tof(int node, int par){
	for (int i=0; i<G[node].size()-1; i++) if (G[node][i]==par) swap(G[node][i], G[node][G[node].size()-1]);
	if (G[node].back()==par) G[node].pop_back();
	for (int v:G[node]) Tof(v, node);
	tof[timer++]=node;
}

int Solve(int k){
	if (val[k]!=-1) return val[k];
	ans=0;
	for (int ind=1; ind<=n; ind++){
		int node=tof[ind];
		int mx1=0, mx2=0;
		for (int v:G[node]){
			mx2=max(mx2, A[v]);
			if (mx2>mx1) swap(mx1, mx2);
		}
		if (mx1+mx2+1>=k){
			ans++;
			A[node]=0;
		}
		else A[node]=mx1+1;
	}
	return val[k]=ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(val, -1, sizeof(val));
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	Tof(1, 1);
	for (int i=1; i<SQ; i++) res[i]=Solve(i);
	for (int i=SQ; i<=n; i++){
		Solve(i);
		int dwn=i, up=n+1;
		while (up-dwn>1){
			int mid=(dwn+up)>>1;
			if (Solve(mid)==val[i]) dwn=mid;
			else up=mid;
		}
		for (int j=i; j<up; j++) res[j]=val[i];
		i=dwn;
	}
	for (int i=1; i<=n; i++) cout<<res[i]<<'\n';
	
	return 0;
}