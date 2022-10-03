#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef double ld;
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
const int MAXN = 18;

int n, m, k, u, v, x, y, t, a, b;
ld A[MAXN][MAXN];
ld dp[1<<MAXN];
bool mark[1<<MAXN];
queue<int> q;

void f(int mask){
	//debug(mask)
	int cnt=0;
	vector<int> vec;
	for (int i=0; i<n; i++){
		if ((mask>>i)&1) vec.pb(i), cnt++;
	}
	for (int i=0; i<cnt; i++) for (int j=i+1; j<cnt; j++){
		int x=vec[i], y=vec[j];
		dp[mask^(1<<x)]+=dp[mask]*A[y][x]/(cnt*(cnt-1)/2);
		dp[mask^(1<<y)]+=dp[mask]*A[x][y]/(cnt*(cnt-1)/2);
	}
	for (int i=0; i<cnt; i++) if (!mark[mask^(1<<vec[i])]){
		q.push(mask^(1<<vec[i]));
		mark[mask^(1<<vec[i])]=1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin>>A[i][j];
	dp[(1<<n)-1]=1;
	q.push((1<<n)-1);
	while (!q.empty()){
		f(q.front());
		q.pop();
	}
	setprecision(6);
	for (int i=0; i<n; i++) cout<<fixed<<dp[1<<i]<<' ';
	
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