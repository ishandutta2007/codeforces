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
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010;

int n, m, k, u, v, x, y, t, a, b, ans;
int dp[MAXN][3];
int par[MAXN][3];
string s, out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>s;
	s='.'+s;
	for (int i=1; i<=n; i++){
		if (dp[i-1][1]<dp[i-1][2]) par[i][0]=1;
		else par[i][0]=2;
		if (dp[i-1][0]<dp[i-1][2]) par[i][1]=0;
		else par[i][1]=2;
		if (dp[i-1][0]<dp[i-1][1]) par[i][2]=0;
		else par[i][2]=1;
		dp[i][0]=min(dp[i-1][1], dp[i-1][2])+1;
		dp[i][1]=min(dp[i-1][0], dp[i-1][2])+1;
		dp[i][2]=min(dp[i-1][0], dp[i-1][1])+1;
		if (s[i]=='R') dp[i][0]--;
		if (s[i]=='G') dp[i][1]--;
		if (s[i]=='B') dp[i][2]--;
	}
	int tmp=min_element(dp[n], dp[n]+3)-dp[n];
	cout<<dp[n][tmp]<<'\n';
	for (int i=n; i; tmp=par[i--][tmp]){
		if (tmp==0) out="R"+out;
		if (tmp==1) out="G"+out;
		if (tmp==2) out="B"+out;
	}
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