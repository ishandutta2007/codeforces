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
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int cnt[4];
vector<int> vec[4];
int b1[MAXN], b2[MAXN];
char ch;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>ch, b1[i]=(ch=='1');
	for (int i=1; i<=n; i++) cin>>ch, b2[i]=(ch=='1');
	for (int i=1; i<=n; i++){
		int state=2*b1[i]+b2[i];
		vec[state].pb(i);
		cnt[state]++;
	}
	for (int i=1; i<=n; i++) a+=b1[i];
	for (int i=1; i<=n; i++) b+=b2[i];
	
	for (int i=0; i<=a; i++){
		int z=b-i;
		if (z<0) continue ;
		for (int j=0; j<=min(cnt[3], min(i, z)); j++){
			if (cnt[2]<i-j) continue ;
			if (cnt[0]<n/2-i-z+j) continue ;
			if (cnt[1]<z-j) continue ;
			if (i-j<0) continue ;
			if (n/2-i-z+j<0) continue ;
			if (z-j<0) continue ;
			for (int x=0; x<n/2-i-z+j; x++) cout<<vec[0][x]<<' ';
			for (int x=0; x<z-j; x++) cout<<vec[1][x]<<' ';
			for (int x=0; x<i-j; x++) cout<<vec[2][x]<<' ';
			for (int x=0; x<j; x++) cout<<vec[3][x]<<' ';
			return 0;
		}
	}
	cout<<"-1\n";
	
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