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
#define prec setprecision(12)<<fixed

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 110;

int r, s, p;
ld dp[MAXN][MAXN][MAXN];
ld ans1, ans2, ans3;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>r>>s>>p;
	dp[r][s][p]=1;
	for (int sum=r+s+p; sum; sum--) for (int a=0; a<=min(sum, r); a++) for (int b=0; b<=min(sum-a, s); b++){
		int c=sum-a-b;
		if (c>p) continue ;
		
		//cerr<<a<<' '<<b<<' '<<c<<" --> "<<dp[a][b][c]<<endl;
		if (a && !b && !c) ans1+=dp[a][0][0];
		if (!a && b && !c) ans2+=dp[0][b][0];
		if (!a && !b && c) ans3+=dp[0][0][c];
		
		if (a==sum || b==sum || c==sum) continue ;
		
		ld t=a*b+b*c+a*c;
		ld p1=a*b/t, p2=b*c/t, p3=a*c/t; 
		if (b) dp[a][b-1][c]+=p1*dp[a][b][c]; 
		if (c) dp[a][b][c-1]+=p2*dp[a][b][c]; 
		if (a) dp[a-1][b][c]+=p3*dp[a][b][c];
		
	}
	cout<<prec<<ans1<<' '<<prec<<ans2<<' '<<prec<<ans3<<endl;
	
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