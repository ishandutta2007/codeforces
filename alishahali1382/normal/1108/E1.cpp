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
const int MAXN = 200010;

int n, m, k, u, v, x, y, t, ind, a, b, ans;
int A[MAXN];
pii C[MAXN];
int dp[MAXN][20];
int S[MAXN];

int RMQ(int l, int r){ // segment [l, r)
	if (l==r) return -inf;
	int x=log2(r-l);
	return max(dp[l][x], dp[r-(1<<x)][x]);
}

int calc(){
	int res=-inf;
	sort(S, S+t);
	int lst=1, cnt=0;
	for (int i=0; i<t; i++){
		res=max(res, RMQ(lst, S[i]/2)-cnt);
		lst=S[i]/2;
		
		if (S[i]&1) cnt--;
		else cnt++;
		while (lst==S[i+1]/2){
			i++;
			if (S[i]&1) cnt--;
			else cnt++;
		}
	}
	return max(res, RMQ(lst, n+3));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i=0; i<MAXN; i++) dp[i][0]=A[i]=-inf;
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i], dp[i][0]=A[i];
	for (int j=1; j<20; j++) for (int i=1; i<MAXN; i++) dp[i][j]=max(dp[i][j-1], dp[min(i+(1<<(j-1)), MAXN-1)][j-1]);
	for (int i=1; i<=m; i++) cin>>C[i].first>>C[i].second, C[i].second++;
	for (int x=1; x<=n; x++){
		t=0;
		for (int i=1; i<=m; i++) if (C[i].first<=x && x<C[i].second) S[t++]=2*C[i].first, S[t++]=2*C[i].second+1;
		int tmp=calc()-A[x]+t/2;
		if (tmp>=ans){
			ans=tmp;
			ind=x;
		}
	}
	cout<<ans<<'\n';
	vector<int> out;
	for (int i=1; i<=m; i++) if (C[i].first<=ind && ind<C[i].second) out.pb(i);
	cout<<out.size()<<'\n';
	for (int i:out) cout<<i<<' ';
	
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