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
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000010LL;
const int mod = 1000000007;
const int MAXN = 1000010;

ll n, m, u, v, x, y, t, a, b, ans;
ll A[MAXN];
int ind[MAXN];
int par[MAXN];
ll sz[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];

bool cmp(int i, int j){ return A[i]<A[j];}

int get(int x){
	if (par[x]==x) return x;
	return par[x]=get(par[x]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=0; i<n-1; i++){
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	for (int i=1; i<MAXN; i++) par[i]=i;
	for (int i=1; i<MAXN; i++) ind[i]=i;
	sort(ind+1, ind+n+1, cmp);
	for (int j=1; j<=n; j++){
		int i=ind[j];
		ll s=0;
		ll tmp=0;
		for (int v:G[i]){
			int x=get(v);
			if (!mark[v]) continue ;
			par[x]=i;
			s+=sz[x];
			ans+=sz[x]*A[i];
			tmp+=sz[x]*sz[x];
		}
		ans+=(s*s-tmp)/2*A[i];
		sz[i]=s+1;
		mark[i]=true;
	}
	debug(ans);
	reverse(ind+1, ind+n+1);
	memset(mark, 0, sizeof(mark));
	memset(sz, 0, sizeof(sz));
	for (int i=1; i<MAXN; i++) par[i]=i;
	
	for (int j=1; j<=n; j++){
		int i=ind[j];
		//debug(i);
		ll s=0, tmp=0;
		for (int v:G[i]){
			int x=get(v);
			if (!mark[v]) continue ;
			par[x]=i;
			s+=sz[x];
			ans-=sz[x]*A[i];
			tmp+=sz[x]*sz[x];
		}
		ans-=(s*s-tmp)/2*A[i];
		sz[i]=s+1;
		mark[i]=true;
		//debug(ans);
	}
	
	
	cout<<ans<<endl;
	
	return 0;
}
/*
          .---.                                                                     .---.              ...-'  |`. ..-'''-.       / .--. \        .-''-.
          |   |.--.                       .                     .                   |   |.--.          |      |  |\.-'''\ \     ' '    ' '     .' .-.  )
          |   ||__|                     .'|                   .'|                   |   ||__|          ....   |  |       | |    \ \    / /    / .'  / /
          |   |.--.                    <  |                  <  |                   |   |.--.            -|   |  |    __/ /      `.`'--.'    (_/   / /
    __    |   ||  |                     | |             __    | |             __    |   ||  |             |   |  |   |_  '.      / `'-. `.        / /
 .:--.'.  |   ||  |                 _   | | .'''-.   .:--.'.  | | .'''-.   .:--.'.  |   ||  |          ...'   `--'      `.  \   ' /    `. \      / /
/ |   \ | |   ||  |               .' |  | |/.'''. \ / |   \ | | |/.'''. \ / |   \ | |   ||  |          |         |`.      \ '. / /       \ '    . '
`" __ | | |   ||  |              .   | /|  /    | | `" __ | | |  /    | | `" __ | | |   ||  |          ` --------\ |       , || |         | |  / /    _.-')
 .'.''| | |   ||__|            .'.'| |//| |     | |  .'.''| | | |     | |  .'.''| | |   ||__|           `---------'        | || |         | |.' '  _.'.-''
/ /   | |_'---'              .'.'.-'  / | |     | | / /   | |_| |     | | / /   | |_'---'                                 / ,' \ \       / //  /.-'_.'
\ \._,\ '/                   .'   \_.'  | '.    | '.\ \._,\ '/| '.    | '.\ \._,\ '/                              -....--'  /   `.'-...-'.'/    _.'
 `--'  `"                               '---'   '---'`--'  `" '---'   '---'`--'  `"                               `.. __..-'       `-...-'( _.-'
*/