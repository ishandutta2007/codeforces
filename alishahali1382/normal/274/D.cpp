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
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
pii B[MAXN];
int L[MAXN];
int R[MAXN];
int deg[2*MAXN];
vector<int> G[MAXN*2], topol;
queue<int> Q;

void addedge(int u, int v){
	G[u].pb(v);
	deg[v]++;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	int A[n][m];
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>A[i][j];
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++) B[j]={A[i][j], j};
		sort(B, B+m);
		//for (int i=0; i<m; i++) cerr<<B[i].first<<' ';cerr<<endl; 
		
		int tmp=(i+1)*(m+1);
		L[0]=tmp;
		for (int j=1; j<m; j++){
			if (B[j-1].first==B[j].first) L[j]=L[j-1];
			else L[j]=j+tmp;
		}
		//debug(L[2])
		
		R[m-1]=tmp+m;
		for (int j=m-2; j>=0; j--){
			if (B[j].first==B[j+1].first) R[j]=R[j+1];
			else R[j]=j+1+tmp;
		}
		
		for (int j=0; j<m; j++) if (B[j].first>=0){
			addedge(L[j], B[j].second);
			addedge(B[j].second, R[j]);
			//cerr<<L[j]<<" --> "<<B[j].second<<endl;
			//cerr<<B[j].second<<" --> "<<R[j]<<endl;
		}
	}
	for (int i=0; i<2*MAXN; i++) if (!deg[i]) Q.push(i);
	while (!Q.empty()){
		int v=Q.front();
		Q.pop();
		//debug(v)
		if (v<m) topol.pb(v);
		for (int i:G[v]) if (!(--deg[i])) Q.push(i);
	}
	if (topol.size()<m) kill(-1)
	for (int i:topol) cout<<i+1<<' ';
	
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