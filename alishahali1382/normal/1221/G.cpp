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
const int MAXN = 40, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans;
ll G[MAXN];
int dp[1<<LOG];
bool ok[1<<LOG];
int And[1<<LOG];
int color[MAXN];
bool mark[MAXN];

bool dfs1(int node, int c){
	color[node]=c;
	for (int v=0; v<n; v++) if ((G[node]>>v)&1) if (color[v]==c || (!color[v] && !dfs1(v, 3-c))) return 0;
	return 1;
}

void dfs2(int node){
	mark[node]=1;
	for (int v=0; v<n; v++) if (((G[node]>>v)&1) && !mark[v]) dfs2(v);
}

// + (none)    -->  1<<n                               done
// - (0)       -->  tedade Independente Set            done
// - (1)       -->  1<<(moalefe haye hambandi)         done
// - (2)       -->  = [- (0)]                          done
// + (0, 1)    -->  1<<(isolated vertices)             done
// + (0, 2)    -->  1<<(moalefe haye bipartite)        done      
// + (1, 2)    -->  1<<(isolated vertices)             done
// - (1, 2, 3) -->  0  :)                              done

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	if (!m) kill(0)
	while (m--){
		cin>>u>>v;u--;v--;
		G[u]|=(1ll<<v);
		G[v]|=(1ll<<u);
	}
	ans=(1ll<<n);
	
	ll iso=0;
	for (int i=0; i<n; i++) iso+=(G[i]==0);
	ans+=2*(1ll<<iso);
	
	ll zarib=0, cnt=0;
	for (int i=0; i<n && !zarib; i++) if (!color[i] && !dfs1(i, 1)) zarib=-1;
	for (int i=0; i<n; i++) if (!mark[i]) cnt++, dfs2(i);
	ans+=zarib*(1ll<<cnt);
	
	int middle=n/2;
	dp[0]=1;
	for (int mask=1; mask<(1<<middle); mask++){
		int v=__builtin_ctz(mask);
		dp[mask]=dp[mask^(1<<v)]&(!(G[v]&mask));
	}
	
	ok[0]=1;
	for (int mask=1; mask<(1<<(n-middle)); mask++){
		int v=__builtin_ctz(mask);
		ok[mask]=ok[mask^(1<<v)]&(!((G[v+middle]>>middle)&mask));
	}
	
	And[0]=(1<<middle)-1;
	for (int mask=1; mask<(1<<(n-middle)); mask++){
		int v=__builtin_ctz(mask);
		And[mask]=And[mask^(1<<v)]&(~G[v+middle]);
	}
	
	for (int j=0; j<middle; j++) for (int i=(1<<middle); i; i--) if (i&(1<<j)) dp[i]+=dp[i^(1<<j)];
	for (int mask=0; mask<(1<<(n-middle)); mask++) if (ok[mask]) ans-=2*dp[And[mask]];
	cout<<ans<<'\n';
	
	return 0;
}
/*
4 4
1 2
2 3
3 4
4 1


*/