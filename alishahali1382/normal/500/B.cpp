#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 510;

int n, m, q, ans, a, b, c;
int A[MAXN];
int B[MAXN];
bool mark[MAXN];
vector<int> G[MAXN];
vector<int> vec, tmp;
char ch;

void dfs(int node){
	mark[node]=true;
	vec.pb(node);
	for (int v:G[node]){
		if (mark[v]) continue ;
		dfs(v);
	}
}

bool cmp(int i, int j){
	return A[i]<A[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i];
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin>>ch;
			if (ch=='1') G[i].pb(j);
		}
	}
	for (int i=1; i<=n; i++){
		if (mark[i]) continue ;
		dfs(i);
		sort(all(vec));
		for (int j:vec) tmp.pb(j);
		sort(all(vec), cmp);
		for (int j:vec) B[j]=A[j];
		for (int j=0; j<vec.size(); j++) A[tmp[j]]=B[vec[j]];
		vec.clear();
		tmp.clear();
	}
	for (int i=0; i<n; i++) cout<<A[i]<<' ';
	cout<<endl;
	
	return 0;
}
/*
                                                                                                            __                    .----.                    
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