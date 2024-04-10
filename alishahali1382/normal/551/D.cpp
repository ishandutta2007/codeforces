#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, pii> mat;
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
const int MAXN = 100010;

ll n, k, l, m, t, x, y, a, b, ans=1;

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a, b-1)%m;
	return powmod(a*a%m, b>>1);
}

mat mul(mat m1, mat m2){
	ll a1=m1.first.first, b1=m1.first.second, c1=m1.second.first, d1=m1.second.second;
	ll a2=m2.first.first, b2=m2.first.second, c2=m2.second.first, d2=m2.second.second;
	return {{(a1*a2+b1*c2)%m, (a1*b2+b1*d2)%m}, {(c1*a2+d1*b2)%m, (c1*b2+d1*d2)%m}};
}

mat fib(mat base, ll a){
	if (a==1) return base;
	if (a&1) return mul(base, fib(base, a-1));
	return fib(mul(base, base), a>>1);
}

mat M={{0, 1}, {1, 1}};

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k>>l>>m;
	if (l<63 && k>=(1ll<<l)) kill(0);
	ll f=fib(M, n+1).second.second;    // for 0
	t=(powmod(2, n)-f+m)%m;            // for 1
	
	//for (int i=1; i<=n; i++) cerr<<"fib "<<i<<" : "<<fib(M, i).first.second<<endl;
	
	debug(f)
	debug(t)
	
	ans=powmod(t, __builtin_popcountll(k))*powmod(f, l-__builtin_popcountll(k))%m;
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