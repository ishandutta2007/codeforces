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
const int MAXN = 14, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
bool HAMP[1<<MAXN][MAXN][MAXN];
int hampar[1<<MAXN][MAXN][MAXN];
int dp[1<<MAXN];
piii par[1<<MAXN];
vector<int> G[MAXN];
bool mark[MAXN][MAXN];

void edge(int x, int y){
	if (mark[x][y]) return ;
	mark[x][y]=mark[y][x]=1;
	cout<<x+1<<' '<<y+1<<'\n';
}

void print(int mask, int x, int y){
	if (__builtin_popcount(mask)<=1) return ;
	//debug2(x+1, y+1)
	if (x==y) for (int i:G[x]) if (mask&(1<<i)) for (int j:G[x]) if ((mask&(1<<j)) && i!=j && HAMP[mask^(1<<x)][i][j]){
		edge(x, i);
		edge(j, x);
		print(mask^(1<<x), i, j);
		return ;
	}
	edge(x, hampar[mask][x][y]);
	print(mask^(1<<x), hampar[mask][x][y], y);
	return ;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		G[--u].pb(--v);
		G[v].pb(u);
		HAMP[(1<<u)|(1<<v)][u][v]=HAMP[(1<<u)|(1<<v)][v][u]=1;
		hampar[(1<<u)|(1<<v)][u][v]=v;
		hampar[(1<<u)|(1<<v)][v][u]=u;
	}
	for (int i=0; i<n; i++) HAMP[1<<i][i][i]=1;
	for (int mask=7; mask<(1<<n); mask++) if (__builtin_popcount(mask)>=3){
		for (int x=0; x<n; x++) if (mask&(1<<x)) for (int y=0; y<n; y++) for (int i:G[x]) if ((mask&(1<<i)) && HAMP[mask^(1<<x)][i][y]){
			HAMP[mask][x][y]=1;
			hampar[mask][x][y]=i;
			break ;
		}
	}
	for (int mask=7; mask<(1<<n); mask++) if (__builtin_popcount(mask)>=3) 	for (int x=0; x<n; x++) for (int i:G[x]) if (mask&(1<<i)) HAMP[mask][x][x]|=HAMP[mask][x][i];
	
	memset(dp, 63, sizeof(dp));
	for (int i=0; i<n; i++) dp[1<<i]=0;
	for (int mask=3; mask<(1<<n); mask++) if (__builtin_popcount(mask)>=3){
		for (int submask=mask; submask; submask=(submask-1)&mask) for (int x=0; x<n; x++) if ((1<<x)&submask) for (int y=0; y<n; y++) if (((1<<y)&submask) && HAMP[submask][x][y]){
			int tmp=dp[(mask^submask)|(1<<x)|(1<<y)] + __builtin_popcount(submask)-(x!=y);
			if (tmp<dp[mask]){
				dp[mask]=tmp;
				par[mask]={{x, y}, submask};
			}
		}
	}
	cout<<dp[(1<<n)-1]<<'\n';
	for (int mask=(1<<n)-1; __builtin_popcount(mask)>1; mask=(mask^par[mask].second)|(1<<par[mask].first.first)|(1<<par[mask].first.second)){
		print(par[mask].second, par[mask].first.first, par[mask].first.second);
		//debug(par[mask].second)
		//debugp(par[mask].first)
	}
	
	//debug(HAMP[(1<<n)-2][1][2])
	
	return 0;
}