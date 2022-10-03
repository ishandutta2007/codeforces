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
const int inf=1000000000;
const int mod = 1000000007;
const int MAXN = 5010;

int n, m, q, l, r, ans, cnt;
string s;
int dp[MAXN][MAXN];
bool pal[MAXN][MAXN];

ll f(int i, int j){
	if (j<i) return 1;
	if (i==j) return 1;
	if (i+1==j && s[i]!=s[j]) return 2;
	if (i+1==j) return 3;
	if (dp[i][j]!=-1) return dp[i][j];
	if (pal[i][j]) return dp[i][j]=f(i+1, j)+f(i, j-1)-f(i+1, j-1)+1;
	return dp[i][j]=f(i+1, j)+f(i, j-1)-f(i+1, j-1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s>>q;
	memset(dp, -1, sizeof(dp));
	for (int i=0; i<s.size(); i++) pal[i][i]=1;
	for (int i=0; i<s.size()-1; i++) pal[i][i+1]=s[i]==s[i+1];
	
	for (int l=2; l<s.size(); l++){
		for (int i=0; i<s.size()-l; i++){
			int j=i+l;
			pal[i][j]=(s[i]==s[j]) && pal[i+1][j-1];
		}
	}
	while (q--){
		cin>>l>>r;
		cout<<f(l-1, r-1)<<'\n';
	}
	cout<<endl;
	/*
	for (int i=0; i<s.size(); i++){
		for (int j=0; j<s.size(); j++) cerr<<check(i, j)<<' ';cerr<<endl;
	}*/
	
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