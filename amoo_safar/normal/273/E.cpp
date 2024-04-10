#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<pll> V[4];
ll cnt[10];
ll dp[Maxn][4];
ll Get(ll l, ll r){
	return ((r - l + 1) * (l + r) / 2LL) % Mod;	
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	V[0].push_back({1, 2});
V[1].push_back({3, 3});
V[2].push_back({4, 4});
V[1].push_back({5, 6});
V[2].push_back({7, 8});
V[0].push_back({9, 12});
V[1].push_back({13, 14});
V[2].push_back({15, 18});
V[0].push_back({19, 26});
V[1].push_back({27, 38});
V[2].push_back({39, 39});
V[0].push_back({40, 56});
V[2].push_back({57, 57});
V[1].push_back({58, 80});
V[2].push_back({81, 84});
V[0].push_back({85, 119});
V[2].push_back({120, 120});
V[1].push_back({121, 173});
V[2].push_back({174, 178});
V[0].push_back({179, 254});
V[2].push_back({255, 259});
V[1].push_back({260, 362});
V[2].push_back({363, 381});
V[0].push_back({382, 536});
V[2].push_back({537, 543});
V[1].push_back({544, 779});
V[2].push_back({780, 804});
V[0].push_back({805, 1145});
V[2].push_back({1146, 1168});
V[1].push_back({1169, 1631});
V[2].push_back({1632, 1717});
V[0].push_back({1718, 2414});
V[2].push_back({2415, 2446});
V[1].push_back({2447, 3506});
V[2].push_back({3507, 3621});
V[0].push_back({3622, 5153});
V[2].push_back({5154, 5259});
V[1].push_back({5260, 7340});
V[2].push_back({7341, 7729});
V[0].push_back({7730, 10865});
V[2].push_back({10866, 11010});
V[1].push_back({11011, 15779});
V[2].push_back({15780, 16297});
V[0].push_back({16298, 23189});
V[2].push_back({23190, 23668});
V[1].push_back({23669, 33032});
V[2].push_back({33033, 34783});
V[0].push_back({34784, 48893});
V[2].push_back({48894, 49548});
V[1].push_back({49549, 71006});
V[2].push_back({71007, 73339});
V[0].push_back({73340, 104351});
V[2].push_back({104352, 106509});
V[1].push_back({106510, 148646});
V[2].push_back({148647, 156526});
V[0].push_back({156527, 220019});
V[2].push_back({220020, 222969});
V[1].push_back({222970, 319529});
V[2].push_back({319530, 330028});
V[0].push_back({330029, 469580});
V[2].push_back({469581, 479293});
V[1].push_back({479294, 668909});
V[2].push_back({668910, 704370});
V[0].push_back({704371, 990086});
V[2].push_back({990087, 1003363});
V[1].push_back({1003364, 1437881});
V[2].push_back({1437882, 1485129});
V[0].push_back({1485130, 2113112});
V[2].push_back({2113113, 2156821});
V[1].push_back({2156822, 3010091});
V[2].push_back({3010092, 3169668});
V[0].push_back({3169669, 4455389});
V[2].push_back({4455390, 4515136});
V[1].push_back({4515137, 6470465});
V[2].push_back({6470466, 6683083});
V[0].push_back({6683084, 9509006});
V[2].push_back({9509007, 9705697});
V[1].push_back({9705698, 13545410});
V[2].push_back({13545411, 14263509});
V[0].push_back({14263510, 20049251});
V[2].push_back({20049252, 20318115});
V[1].push_back({20318116, 29117093});
V[2].push_back({29117094, 30073876});
V[0].push_back({30073877, 42790529});
V[2].push_back({42790530, 43675639});
V[1].push_back({43675640, 60954347});
V[2].push_back({60954348, 64185793});
V[0].push_back({64185794, 90221630});
V[2].push_back({90221631, 91431520});
V[1].push_back({91431521, 131026919});
V[2].push_back({131026920, 135332445});
V[0].push_back({135332446, 192557381});
V[2].push_back({192557382, 196540378});
V[1].push_back({196540379, 274294562});
V[2].push_back({274294563, 288836071});
V[0].push_back({288836072, 405997337});
V[2].push_back({405997338, 411441843});
V[1].push_back({411441844, 589621136});
V[2].push_back({589621137, 608996005});
V[0].push_back({608996006, 866508215});
V[2].push_back({866508216, 884431704});
V[1].push_back({884431705, 1000000000});
	
	ll n, p;
	cin >> n >> p;
	p--;
	for(int i = 0; i < 3; i++)
		for(auto x : V[i]){
			if(p < x.F) continue;
			ll C = min(x.S, p) - x.F + 1;
			cnt[i] += (p + 1) * C - Get(x.F, min(x.S, p));
			cnt[i] %= Mod;
		}
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 4; j++){
			dp[i][j] %= Mod;
			for(int k = 0; k < 3; k++)
				dp[i + 1][j ^ k] += dp[i][j] * cnt[k];
		}
	
	cout << (dp[n][1] + dp[n][2] + dp[n][3]) % Mod;
	return 0;
}