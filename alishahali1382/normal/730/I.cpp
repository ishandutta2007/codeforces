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
const int MAXN = 3010;

int n, m, k, p, s, x, y, t, a, b, ans;
pii A[MAXN];
int B[MAXN];
int dp[MAXN][MAXN];
int upd[MAXN][MAXN];
bool mark[MAXN];
vector<int> out, out2;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>p>>s;
	for (int i=1; i<=n; i++){
		cin>>x;
		A[i]={x, i};
	}
	for (int i=1; i<=n; i++) cin>>B[i];
	sort(A+1, A+n+1);
	reverse(A+1, A+n+1);
	memset(dp, -63, sizeof(dp));
	dp[0][0]=0;
	for (int i=1; i<=n; i++){
		int a=A[i].first, ind=A[i].second;
		dp[i][0]=dp[i-1][0]+(i<=p)*a;
		for (int j=1; j<=s; j++){
			dp[i][j]=dp[i-1][j]+(i-j<=p)*a;
			int tmp=dp[i-1][j-1]+B[ind];
			if (tmp>dp[i][j]){
				dp[i][j]=tmp;
				upd[i][j]=1;
			}
		}
	}
	cout<<dp[n][s]<<endl;
	for (int i=n, j=s; i; i--){
		if (!upd[i][j]) continue ;
		out2.pb(A[i].second);
		mark[A[i].second]=1;
		j--;
	}
	for (int i=1, j=p; i<=n && p; i++){
		if (mark[A[i].second]) continue ;
		p--;
		out.pb(A[i].second);
	}
	sort(all(out));
	sort(all(out2));
	for (int i:out) cout<<i<<' ';cout<<'\n';
	for (int i:out2) cout<<i<<' ';cout<<'\n';
	
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