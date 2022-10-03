#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
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

ll n, m, u, v, x, y, t, a, b, ans, mx, cf, cm, cnt;
pii A[MAXN];
ll val[MAXN];
ll out[MAXN];
ll ps[MAXN];
ll ps2[MAXN];

ll f(ll x, int t){
	ll dwn=0, up=mx+1;
	while (up-dwn>1){
		ll mid=(dwn+up)/2;
		ll tmp=lower_bound(val+1, val+n-t+1, mid)-val-1;
		if (tmp*mid-ps[tmp]>x) up=mid;
		else dwn=mid;
	}
	return dwn;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>mx>>cf>>cm>>m;
	for (int i=1; i<=n; i++){
		cin>>A[i].first;
		A[i].second=i;
	}
	sort(A+1, A+n+1);
	for (int i=1; i<=n; i++) val[i]=A[i].first;
	val[n+1]=INF;
	for (int i=1; i<=n; i++) ps[i]=ps[i-1]+val[i];
	for (int i=1; i<=n; i++) ps2[i]=ps2[i-1]+val[n-i+1];
	
	for (int i=0; i<=n; i++){
		ll x=mx*i-ps2[i];
		if (x>m) break ;
		ll t=f(m-x, i)*cm+i*cf;
		//cerr<<i<<' '<<t<<endl;
		if (t>=ans){
			ans=t;
			cnt=i;
		}
	}
	cout<<ans<<endl;
	ll x=mx*cnt-ps2[cnt];
	ll t=f(m-x, cnt);
	for (int i=0; i<cnt; i++) A[n-i].first=mx;
	for (int i=1; A[i].first<t; i++) A[i].first=t;
	for (int i=1; i<=n; i++) out[A[i].second]=A[i].first;
	for (int i=1; i<=n; i++) cout<<out[i]<<' ';
	
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