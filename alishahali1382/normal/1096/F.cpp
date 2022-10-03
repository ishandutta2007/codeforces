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
const int mod = 998244353;
const int MAXN = 200010;

ll powmod(ll a, ll b){
	if (!b) return 1;
	if (b&1) return a*powmod(a, b-1)%mod;
	return powmod(a*a%mod, b>>1);
}
ll n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
ll F[MAXN];
int cnt[MAXN];
bool mark[MAXN];
ll BIT[MAXN];

void upd(int ind, int x){
	for (; ind<=n; ind+=(ind&(-ind))) BIT[ind]+=x;
}

ll get(int ind){
	ll res=0;
	for (; ind; ind-=(ind&(-ind))) res+=BIT[ind];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F[0]=1;
	for (int i=1; i<MAXN; i++) F[i]=(F[i-1]*i)%mod;
	ll fff=1;
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], t+=(A[i]==-1);
	ll fact=1;
	for (int i=3; i<=t; i++) fact=(fact*i)%mod;
	if (t>=2) ans=((t*(t-1)/2)%mod)*fact%mod;
	debug(ans);
	for (int i=1; i<=n; i++){
		cnt[i]=cnt[i-1];
		if (A[i]==-1) cnt[i]++;
		else mark[A[i]]=1;
	}
	vector<int> vec;
	for (int i=1; i<=n; i++) if (!mark[i]) vec.pb(i);
	for (int i=n; i; i--){
		if (A[i]==-1) continue ;
		ans=(ans+F[t]*get(A[i]))%mod;
		upd(A[i], 1);
	}
	for (int i=1; i<=n; i++){
		if (A[i]==-1) continue ;
		ll tl=cnt[i], tr=t-tl;
		ll sml=lower_bound(all(vec), A[i])-vec.begin(), lrg=t-sml;
		//cerr<<A[i]<<' '<<sml<<' '<<lrg<<endl;
		//cerr<<A[i]<<' '<<tl<<' '<<tr<<endl;
		ans=(ans+(F[t-1]*tl%mod)*lrg)%mod;
		ans=(ans+(F[t-1]*tr%mod)*sml)%mod;
	}
	cout<<ans*powmod(F[t], mod-2)%mod<<endl;
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