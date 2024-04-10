#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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
const int N=13;

ll n, m, q, u, v, x, y, t, a, b, ans;
ll dp[1<<N][N];
vector<int> G[N];
vector<pii> LCA[N];

bool check(int root, int mask1, int mask2){
	for (int i=0; i<n; i++) if ((1<<i)&mask2) for (pii p:LCA[i]) if ((1<<p.first)&mask1 && root!=p.second || (1<<p.first)&mask2 && root==p.second) return 0;
	mask1^=(1<<root);
	for (int i=0; i<n; i++) if ((1<<i)&mask2) for (int j:G[i]) if ((1<<j)&mask1) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	while (m--){
		cin>>u>>v;
		u--;v--;
		G[u].pb(v);
		G[v].pb(u);
	}
	while (q--){
		cin>>a>>b>>x;
		a--;b--;x--;
		if (a==b && a!=x) kill(0)
		LCA[a].pb({b, x});
		LCA[b].pb({a, x});
	}
	for (int i=0; i<n; i++) dp[1<<i][i]=1;
	for (int mask=1; mask<(1<<n); mask++) if (__builtin_popcount(mask)>1) for (int root=0; root<n; root++) if (mask&(1<<root)){
		int M=mask^(1<<root);
		for (int MM=M; MM; MM=(MM-1)&M) if (__builtin_ctz(MM)==__builtin_ctz(M)){
			int cnt=0, tmp=0;
			for (int v:G[root]) if ((1<<v)&MM) cnt++, tmp=v;
			if (cnt>1 || !check(root, mask^MM, MM)) continue ;
			if (cnt==1){
				dp[mask][root]+=dp[mask^MM][root]*dp[MM][tmp];
				continue ;
			}
			for (int R=0; R<n; R++) if ((1<<R)&MM) dp[mask][root]+=dp[mask^MM][root]*dp[MM][R];
		}
	}
	cout<<dp[(1<<n)-1][0]<<'\n';
	
	return 0;
}