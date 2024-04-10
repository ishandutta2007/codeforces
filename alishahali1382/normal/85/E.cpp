#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 5010;

int n, ans, k, t, x, y, a, b;
pii A[MAXN];
bool mark[MAXN];
bool color[MAXN];

int dis(int a, int b){
	return abs(A[a].first-A[b].first)+abs(A[a].second-A[b].second);
}

set<int> st;

bool dfs(int node, int c, int d){
	//debug(node);
	mark[node]=true;
	color[node]=c;
	for (int i=0; i<n; i++){
		if (i==node || dis(node, i)<=d) continue ;
		if (mark[i] && color[i]==c) return false;
		if (!mark[i] && !dfs(i, 1-c, d)) return false;
	}
	return true;
}

int check(int d){
	memset(mark, 0, sizeof(mark));
	memset(color, 0, sizeof(color));
	//for (int i=0; i<n; i++) st.insert(i);
	int res=0;
	for (int i=0; i<n; i++){
		if (mark[i]) continue ;
		if (!dfs(i, 1, d)) return 0;
		res++;
	}
	return res;
}

int tav(int x){
	int res=1;
	while (x--) res=(res*2)%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) cin>>A[i].first>>A[i].second;
	
	int l=-1, r=10000;
	while (r-l>1){
		int mid=(l+r)/2;
		//cerr<<l<<' '<<mid<<' '<<r<<endl;
		if (check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<endl;
	cout<<tav(check(r))<<endl;
	
	
	//debug(check(1));
	//debug(dfs(0, 1, 1));
	
	
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