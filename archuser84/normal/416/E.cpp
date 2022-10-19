///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    Padoru Padoru   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;

const int N = 510;
ll dis[N][N];
ll A[N][N];
const ll inf = 1e9;
int n, m;
bitset<N> bs[N][N];
int cnt[N][N];

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	Loop(i,0,N) Loop(j,0,N) A[i][j] = dis[i][j] = inf;
	Loop(i,0,N) dis[i][i] = 0;
	cin >> n >> m;
	while(m--){
		int v, u, w;
		cin >> v >> u >> w; --v; --u;
		dis[v][u] = dis[u][v] = w;
		A[v][u] = A[u][v] = w;
	}
	Loop(k,0,n) Loop(i,0,n) Loop(j,0,n)
		dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	Loop(i,0,n) Loop(j,0,n) Loop(k,0,n){
		if(dis[i][k]+dis[k][j] == dis[i][j] && dis[i][j] != inf) bs[i][j][k]=1;
		if(dis[i][k]+A[k][j] == dis[i][j] && dis[i][j] != inf) ++cnt[i][j];
	}
	Loop(i,0,n) Loop(j,i+1,n) {
		int ans = 0;
		Loop(k,0,n) ans += bs[i][j][k]*cnt[i][k];
		cout << ans << ' ';
	}
	cout << '\n';
}