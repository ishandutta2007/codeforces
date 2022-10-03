#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef unsigned long long ll;
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
#define upd(x, y) x=min(x, y)

const int mod=1000000007;
const int N=55, SGM=103;

int n, m, k, u, v, x, y, t, a, b;
int C[N][2], F[N], bad[N], ts;
int A[SGM];
bool mark[SGM], mark2[SGM];
int topol[SGM], sz;
vector<int> B[SGM];
ll dp[N][N][SGM];
ll d0[N], d1[N];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>k>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>A[i]>>x;
		B[i].resize(x);
		for (int j=0; j<x; j++) cin>>B[i][j];
	}
	mark[0]=mark[1]=1;
	for (int shit=0; shit<=n; shit++){
		for (int i=1; i<=n; i++) if (!mark2[i]){
			bool ok=1;
			for (int j:B[i]) if (!mark[j]) ok=0;
			if (ok){
				mark[A[i]]=1;
				mark2[i]=1;
				topol[sz++]=i;
			}
		}
	}
	// ------------------
	for (int i=0; i<m; i++){
		int v=0;
		cin>>x;
		while (x--){
			cin>>a;
			if (!C[v][a]) C[v][a]=++ts;
			v=C[v][a];
		}
		bad[v]=1;
	}
	queue<int> Q;
	for (int i:{0, 1}) if (C[0][i]) Q.push(C[0][i]);
	while (Q.size()){
		int v=Q.front();
		Q.pop();
		bad[v]|=bad[F[v]];
		for (int i:{0, 1}){
			if (!C[v][i]) C[v][i]=C[F[v]][i];
			else{
				F[C[v][i]]=C[F[v]][i];
				Q.push(C[v][i]);
			}
		}	
	}
	// -------------------------
	memset(dp, 63, sizeof(dp)); // maybe not big enough :(
	ll INF=dp[0][0][0];
	for (int v=0; v<=ts; v++) if (!bad[v]) for (int i:{0, 1}){
		int u=C[v][i];
		if (bad[u]) continue ;
		dp[v][u][i]=1;
	}
	for (int shit=0; shit<18; shit++){
		for (int v=0; v<=ts; v++) if (!bad[v]){
			for (int ii=0; ii<sz; ii++){
				int i=topol[ii], c=A[i];
				memset(d0, 63, sizeof(d0));
				d0[v]=0;
				for (int x:B[i]){
					memcpy(d1, d0, sizeof(d1));
					memset(d0, 63, sizeof(d0));
					for (int u=0; u<=ts; u++) if (!bad[u]) for (int vv=0; vv<=ts; vv++){
						upd(d0[vv], d1[u]+dp[u][vv][x]);
					}
				}
				for (int u=0; u<=ts; u++) upd(dp[v][u][c], d0[u]);
			}
		}
	}
	
	for (int i=2; i<k; i++){
		if (!mark[i]) cout<<"YES\n";
		else{
			ll ans=INF;
			for (int v=0; v<=ts; v++) if (!bad[v]) ans=min(ans, dp[0][v][i]);
			if (ans==INF) cout<<"YES\n";
			else cout<<"NO "<<ans<<"\n";
		}
	}
	
	return 0;
}