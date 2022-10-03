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
const int MAXN = 1010, M=200010;

int n, m, q, u, v, x, y, a, b;
int f[MAXN][MAXN];
int ans[M];
int E[M][2];
int l[M], r[M], s[M], t[M];
vector<int> Q[M];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int i=1; i<=m; i++) cin>>E[i][0]>>E[i][1];
	for (int i=1; i<=q; i++) cin>>l[i]>>r[i]>>s[i]>>t[i], Q[l[i]].pb(i);
	memset(f, inf, sizeof(f));
	for (int i=1; i<=n; i++) f[i][i]=0;
	for (int i=m; i; i--){
		int u=E[i][0], v=E[i][1];
		for (int shit=0; shit<2; shit++){
			for (int x=1; x<=n; x++) f[u][x]=min(f[u][x], max(i, f[v][x]));
			swap(u, v);
		}
		for (int id:Q[i]) ans[id]=(f[s[id]][t[id]]<=r[id]);
	}
	for (int i=1; i<=q; i++) cout<<(ans[i]?"Yes":"No")<<'\n';
	
	return 0;
}