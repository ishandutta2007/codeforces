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
const int MAXN = 100010;

int n, m, k, u, v, x, y, t, cnt, ans;
int A[MAXN];
string s[MAXN];
map<string, int> mp;
bitset<40> B[MAXN];
bool G[40][40];
int dp[1<<20];

bool ok(ll mask){
	vector<int> vec;
	for (int i=n; i<m; i++) if (mask&(1ll<<i)) vec.pb(i);
	for (int i:vec) for (int j:vec) if (mask&(1ll<<i) && mask&(1ll<<j) && G[i][j] && i!=j) return 0;
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		if (A[i]==2){
			cin>>s[i];
			if (!mp.count(s[i])) mp[s[i]]=t++;
		}
	}
	for (int i=n; i; i--){
		k=A[i];
		if (k==1) cnt++;
		else B[cnt][mp[s[i]]]=1;
	}
	vector<int> vec;
	for (int i=0; i<cnt; i++){
		for (int j=0; j<m; j++) if (B[i][j]) vec.pb(j);
		for (int x:vec) for (int y:vec) G[x][y]=1;
		vec.clear();
	}
	for (int i=0; i<m; i++) G[i][i]=1;
	n=(m+1)/2;
	
	//-------------------------------------------------------
	dp[0]=0;
	for (int mask=1; mask<(1<<n); mask++){
		int tmp=mask, v=__builtin_ctz(mask);
		dp[mask]=dp[mask^(1<<v)];
		for (int i=0; i<n; i++) if (G[v][i] && (tmp&(1<<i))) tmp^=(1<<i);
		dp[mask]=max(dp[mask], dp[tmp]+1);
	}
	ans=dp[(1<<n)-1];
	//-------------------------------------------------------
	for (ll mask=1; mask<(1ll<<(m-n)); mask++){
		bool f=0;
		if (!ok(mask<<n)) continue ;
		int tmp=0;
		for (int i=n; i<m; i++) if (mask&(1ll<<(i-n))) for (int j=0; j<n; j++) if (G[i][j]) tmp|=(1ll<<j);
		ans=max(ans, dp[tmp^((1ll<<n)-1)]+__builtin_popcount(mask));
	}
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