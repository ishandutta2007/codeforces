#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 100010;

ll n, m, b, x, y, out;
int A[MAXN];
int val[MAXN];
int cnt[30][2];
int bit[MAXN][30][2]; // I swear this is not Fenwick!
ll ans[30];
vector<int> G[MAXN];

void dfs(int node, int p){
	//cerr<<"dfs "<<node<<' '<<p<<' '<<t<<endl;
	//for (int i=0; i<25; i++) bit[node][i][0]=1;
	for (int i=0; i<25; i++){
		if ((1<<i)&A[node]) bit[node][i][1]++;
		else bit[node][i][0]++;
	}
	for (int v:G[node]){
		if (v==p) continue ;
		dfs(v, node);
		for (int i=0; i<25; i++){
			if ((1<<i)&A[node]){
				bit[node][i][1]+=bit[v][i][0];
				bit[node][i][0]+=bit[v][i][1];
			}
			else{
				bit[node][i][0]+=bit[v][i][0];
				bit[node][i][1]+=bit[v][i][1];
			}
		}
	}
	
	memset(cnt, 0, sizeof(cnt));
	for (int v:G[node]){
		if (v==p) continue ;
		for (int i=0; i<25; i++){
			cnt[i][0]+=bit[v][i][0];
			cnt[i][1]+=bit[v][i][1];
		}
	}
	
	int t0, t1;
	for (int v:G[node]){
		if (v==p) continue ;
		for (int i=0; i<25; i++){
			if ((1<<i)&A[node]){
				t0=(cnt[i][0]-bit[v][i][0]);
				t1=(cnt[i][1]-bit[v][i][1]);
				ans[i]+=t0*bit[v][i][0]+t1*bit[v][i][1];
			}
			else{
				t0=(cnt[i][0]-bit[v][i][0]);
				t1=(cnt[i][1]-bit[v][i][1]);
				ans[i]+=t0*bit[v][i][1]+t1*bit[v][i][0];
			}
			//if ((t1 || t0) && i<5) cerr<<node<<' '<<v<<' '<<i<<' '<<t0<<' '<<t1<<endl;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<n; i++){
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	dfs(1, 0);/*
	for (int i=1; i<=n; i++){
		for (int j=0; j<5; j++) cerr<<bit[i][j][0]<<' ';
		cerr<<endl;
		for (int j=0; j<5; j++) cerr<<bit[i][j][1]<<' ';
		cerr<<endl<<endl;
		
	}*/
	for (int i=0; i<25; i++) ans[i]/=2;
	for (int node=1; node<=n; node++) for (int i=0; i<25; i++) ans[i]+=bit[node][i][1];
	for (int i=0; i<25; i++) out+=ans[i]*(1ll<<i);
	cout<<out<<endl;
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