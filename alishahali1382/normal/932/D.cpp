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
const int MAXN = 400010, LOG=20;

ll n, m, k, u, v, X, cnt=1, t, r, w, last;
ll W[MAXN];
int h[MAXN];
int par[MAXN][LOG];
ll sum[MAXN][LOG];

void add(){
	cin>>r>>w;
	r^=last;
	w^=last;
	//cerr<<"add "<<r<<' '<<w<<endl;
	W[++cnt]=w;
	if (W[r]>=W[cnt]) par[cnt][0]=r;
	else{
		for (int i=LOG-1; i>=0; i--) if (W[par[r][i]]<W[cnt]) r=par[r][i];
		par[cnt][0]=par[r][0];
	}
	sum[cnt][0]=W[cnt];
	h[cnt]=h[par[cnt][0]]+1;
	for (int i=1; i<LOG; i++){
		par[cnt][i]=par[par[cnt][i-1]][i-1];
		sum[cnt][i]=sum[cnt][i-1]+sum[par[cnt][i-1]][i-1];
	}
}

void query(){
	cin>>r>>X;
	r^=last;
	X^=last;
	//cerr<<"query "<<r<<' '<<X<<endl;
	last=0;
	ll mn=h[r];
	if (W[r]<=X){
		//last++;
		for (int i=LOG-1; i>=0; i--) if (X>=sum[r][i]){
			X-=sum[r][i];
			last+=(1<<i);
			r=par[r][i];
		}
	}
	//last=min(last, mn);
	cout<<last<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	W[0]=INF;
	for (int i=0; i<LOG; i++) sum[0][i]=INF;
	sum[1][0]=0;
	for (int i=1; i<LOG; i++) sum[1][i]=INF;
	h[1]=1;
	int Q, typ;
	cin>>Q;
	while (Q--){
		cin>>typ;
		if (typ==1) add();
		else query();
	}
	
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