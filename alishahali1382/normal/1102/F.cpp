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
const int MAXN = 10010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[16][MAXN];
int val1[16][16];
int val2[16][16];
int dp[16][16][1<<16];

void init(){
	memset(val1, 63, sizeof(val1));
	memset(val2, 63, sizeof(val2));
	for (int i=0; i<n; i++) for (int j=0; j<n; j++){
		for (int x=0; x<m; x++) val1[i][j]=min(val1[i][j], abs(A[i][x]-A[j][x]));
		for (int x=0; x<m-1; x++) val2[i][j]=min(val2[i][j], abs(A[i][x]-A[j][x+1]));
	}
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", &A[i][j]);
	init();
	for (int i=0; i<n; i++) dp[i][i][1<<i]=inf;
	for (int mask=1; mask<(1<<n); mask++) for (int i=0; i<n; i++) for (int j=0; j<n; j++){
		if (!(mask&(1<<i))) break ;
		if (!(mask&(1<<j))) continue ;
		for (int x=0; x<n; x++){
			if (!(mask&(1<<x))) continue ;
			dp[i][j][mask]=max(dp[i][j][mask], min(dp[i][x][mask^(1<<j)], val1[x][j]));
		}
	}
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) ans=max(ans, min(dp[i][j][(1<<n)-1], val2[i][j]));
	
	printf("%d\n", ans);
	
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