#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pii> plii;
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
const int MAXN = 2010;

ll n, m, k, u, v, x, y, t1, t2, s1, s2, ans;
int A[MAXN];
int B[MAXN];
plii X[MAXN*MAXN];
plii Y[MAXN*MAXN];
pli XX[MAXN*MAXN];
pli YY[MAXN*MAXN];
vector<pii> out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i], s1+=A[i], XX[i-1]={A[i], i};
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++) X[t1++]={A[i]+A[j], {i, j}};
	cin>>m;
	for (int i=1; i<=m; i++) cin>>B[i], s2+=B[i], YY[i-1]={B[i], i};
	for (int i=1; i<=m; i++) for (int j=i+1; j<=m; j++) Y[t2++]={B[i]+B[j], {i, j}};
	ans=abs(s1-s2);
	
	sort(X, X+t1);
	sort(Y, Y+t2);
	for (int i=0, j=0; i<t1 && t2; i++){
		ll a=X[i].first, b=Y[j].first;
		while (j+1<t2 && s1-a+b<s2-b+a) b=Y[++j].first;
		ll val=abs(s1-a+b-(s2-b+a));
		if (val<ans){
			ans=val;
			out.clear();
			pii p1=X[i].second, p2=Y[j].second;
			out.pb({p1.first, p2.first});
			out.pb({p1.second, p2.second});
		}
	}
	//debug(ans);
	
	sort(XX, XX+n);
	sort(YY, YY+m);
	for (int i=0, j=0; i<n; i++){
		ll a=XX[i].first, b=YY[j].first;
		while (j+1<m && s1-a+b<s2-b+a) b=YY[++j].first;
		ll val=abs(s1-a+b-(s2-b+a));
		if (val<ans){
			ans=val;
			out.clear();
			int x=XX[i].second, y=YY[j].second;
			out.pb({x, y});
		}
	}
	
	cout<<ans<<endl;
	cout<<out.size()<<endl;
	for (pii p:out) cout<<p.first<<' '<<p.second<<endl;
	
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