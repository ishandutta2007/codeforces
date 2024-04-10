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
const ll INF=10000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010;

int n, m, k, u, v, x, y, t, a, b, ans;
ll A[MAXN];
ll dp[MAXN][5];
string s;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>s;
	for (int i=1; i<=n; i++) cin>>A[i];
	memset(dp, 63, sizeof(dp));
	for (int i=0; i<5; i++) dp[0][i]=0;
	for (int i=1; i<=n; i++){
		char ch=s[i-1];
		if (ch!='h' && ch!='a' && ch!='r' && ch!='d') for (int j=1; j<=4; j++) dp[i][j]=dp[i-1][j];
		if (ch=='h') {
			dp[i][1]=dp[i-1][1]+A[i];
			for (int j=1; j<=4; j++) if (j!=1) dp[i][j]=dp[i-1][j];
		}
		if (ch=='a') {
			dp[i][2]=min(dp[i-1][1], dp[i-1][2]+A[i]);
			for (int j=1; j<=4; j++) if (j!=2) dp[i][j]=dp[i-1][j];
		}
		if (ch=='r') {
			dp[i][3]=min(dp[i-1][2], dp[i-1][3]+A[i]);
			for (int j=1; j<=4; j++) if (j!=3) dp[i][j]=dp[i-1][j];
		}
		if (ch=='d') {
			dp[i][4]=min(dp[i-1][3], dp[i-1][4]+A[i]);
			for (int j=1; j<=4; j++) if (j!=4) dp[i][j]=dp[i-1][j];	
		}
	}
	cout<<dp[n][4]<<endl;
	
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