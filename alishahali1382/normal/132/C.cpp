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

int n, m, k, u, v, x, y, t, a, b, ans, cnt;
int A[MAXN];
string s;

bool dp1[101][205][51]; // dp1[i][j][k] --> i commands   at point j    k changes  going right
bool dp2[101][205][51]; // dp2[i][j][k] --> i commands   at point j    k changes  going left

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>s>>n;
	dp1[0][101][0]=1;
	for (int i=1; i<=s.size(); i++){
		char ch=s[i-1];
		if (ch=='T') cnt++;
		for (int j=1; j<=201; j++){
			if (ch=='F'){
				dp1[i][j][0]=dp1[i-1][j-1][0];
				dp2[i][j][0]=dp2[i-1][j+1][0];
				for (int k=1; k<=n; k++){
					dp1[i][j][k]=dp1[i-1][j-1][k] | dp2[i-1][j][k-1];
					dp2[i][j][k]=dp2[i-1][j+1][k] | dp1[i-1][j][k-1];	
				}
			}
			else{
				dp1[i][j][0]=dp2[i-1][j][0];
				dp2[i][j][0]=dp1[i-1][j][0];
				for (int k=1; k<=n; k++){
					dp1[i][j][k]=dp2[i-1][j][k] | dp1[i-1][j-1][k-1];
					dp2[i][j][k]=dp1[i-1][j][k] | dp2[i-1][j+1][k-1];	
				}
			}
			for (int k=2; k<=n; k++){
				dp1[i][j][k]|=dp1[i][j][k-2];
				dp2[i][j][k]|=dp2[i][j][k-2];
			}
		}
	}
	for (int j=0; j<205; j++) if (dp1[s.size()][j][n] || dp2[s.size()][j][n]) ans=max(ans, abs(101-j));
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