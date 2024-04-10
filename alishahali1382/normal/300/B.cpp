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

int n, m, b, x, y, ans;
bool mark[MAXN];
vector<int> G[MAXN];
vector<vector<int>> out, two;
vector<int> tmp, vec;

vector<int> dfs(int node){
	//cerr<<"dfs "<<node<<' '<<p<<' '<<t<<endl;
	vector<int> res;
	res.pb(node);
	mark[node]=true;
	for (int i:G[node]){
		if (mark[i]) continue ;
		for (auto j:dfs(i)) res.pb(j);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
	}
	for (int i=1; i<=n; i++){
		if (mark[i]) continue ;
		tmp=dfs(i);
		if (tmp.size()>3){
			cout<<-1<<endl;
			return 0;
		}
		if (tmp.size()==3) out.pb(tmp);
		if (tmp.size()==2) two.pb(tmp);
		if (tmp.size()==1) vec.pb(tmp[0]);
	}
	if (two.size()>vec.size()){
		cout<<-1<<endl;
		return 0;		
	}
	for (auto v:out) cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<endl;
	for (int i=0; i<two.size(); i++) cout<<two[i][0]<<' '<<two[i][1]<<' '<<vec[i]<<endl;
	for (int i=two.size(); i<vec.size(); i+=3) cout<<vec[i]<<' '<<vec[i+1]<<' '<<vec[i+2]<<endl;
	
	
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