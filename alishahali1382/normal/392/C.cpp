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
const int MAXN = 110, LOG=20;

struct MAT{
	ll a[MAXN][MAXN];
	MAT(){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]=0;}
	void relax(){ for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) a[i][j]%=mod;}
	
} T;

void zarb(MAT &m1, MAT &m2){
	MAT tmp;
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) for (int k=0; k<MAXN; k++) tmp.a[i][j]+=m1.a[i][k]*m2.a[k][j]%mod;
	tmp.relax();
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) m1.a[i][j]=tmp.a[i][j];
}

void tavan(MAT &M, ll x){
	MAT tmp;
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) tmp.a[i][j]=M.a[i][j];
	x--;
	for (; x; x>>=1, zarb(tmp, tmp)) if (x&1) zarb(M, tmp); 
}

ll n, m, k, u, v, x, y, t, a, b, ans;
ll C[45][45];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<45; i++){
		C[i][0]=C[i][i]=1;
		for (int j=1; j<i; j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for (int i=0; i<=40; i++) for (int j=0; j<=40; j++) T.a[i][j+41]=T.a[i+41][j]=T.a[i+41][j+41]=C[i][j];
	T.a[82][82]=1;
	
	cin>>n>>k;
	T.a[82][41+k]=1;
	
	tavan(T, n);
	
	for (int i=0; i<82; i++) ans=(ans+T.a[82][i])%mod;
	cout<<ans<<'\n';
	
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