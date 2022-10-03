#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b;
vector<pii> vec[3];
void Build(){
vec[0].pb({1, 2});
vec[1].pb({3, 3});
vec[2].pb({4, 4});
vec[1].pb({5, 6});
vec[2].pb({7, 8});
vec[0].pb({9, 12});
vec[1].pb({13, 14});
vec[2].pb({15, 18});
vec[0].pb({19, 26});
vec[1].pb({27, 38});
vec[2].pb({39, 39});
vec[0].pb({40, 56});
vec[2].pb({57, 57});
vec[1].pb({58, 80});
vec[2].pb({81, 84});
vec[0].pb({85, 119});
vec[2].pb({120, 120});
vec[1].pb({121, 173});
vec[2].pb({174, 178});
vec[0].pb({179, 254});
vec[2].pb({255, 259});
vec[1].pb({260, 362});
vec[2].pb({363, 381});
vec[0].pb({382, 536});
vec[2].pb({537, 543});
vec[1].pb({544, 779});
vec[2].pb({780, 804});
vec[0].pb({805, 1145});
vec[2].pb({1146, 1168});
vec[1].pb({1169, 1631});
vec[2].pb({1632, 1717});
vec[0].pb({1718, 2414});
vec[2].pb({2415, 2446});
vec[1].pb({2447, 3506});
vec[2].pb({3507, 3621});
vec[0].pb({3622, 5153});
vec[2].pb({5154, 5259});
vec[1].pb({5260, 7340});
vec[2].pb({7341, 7729});
vec[0].pb({7730, 10865});
vec[2].pb({10866, 11010});
vec[1].pb({11011, 15779});
vec[2].pb({15780, 16297});
vec[0].pb({16298, 23189});
vec[2].pb({23190, 23668});
vec[1].pb({23669, 33032});
vec[2].pb({33033, 34783});
vec[0].pb({34784, 48893});
vec[2].pb({48894, 49548});
vec[1].pb({49549, 71006});
vec[2].pb({71007, 73339});
vec[0].pb({73340, 104351});
vec[2].pb({104352, 106509});
vec[1].pb({106510, 148646});
vec[2].pb({148647, 156526});
vec[0].pb({156527, 220019});
vec[2].pb({220020, 222969});
vec[1].pb({222970, 319529});
vec[2].pb({319530, 330028});
vec[0].pb({330029, 469580});
vec[2].pb({469581, 479293});
vec[1].pb({479294, 668909});
vec[2].pb({668910, 704370});
vec[0].pb({704371, 990086});
vec[2].pb({990087, 1003363});
vec[1].pb({1003364, 1437881});
vec[2].pb({1437882, 1485129});
vec[0].pb({1485130, 2113112});
vec[2].pb({2113113, 2156821});
vec[1].pb({2156822, 3010091});
vec[2].pb({3010092, 3169668});
vec[0].pb({3169669, 4455389});
vec[2].pb({4455390, 4515136});
vec[1].pb({4515137, 6470465});
vec[2].pb({6470466, 6683083});
vec[0].pb({6683084, 9509006});
vec[2].pb({9509007, 9705697});
vec[1].pb({9705698, 13545410});
vec[2].pb({13545411, 14263509});
vec[0].pb({14263510, 20049251});
vec[2].pb({20049252, 20318115});
vec[1].pb({20318116, 29117093});
vec[2].pb({29117094, 30073876});
vec[0].pb({30073877, 42790529});
vec[2].pb({42790530, 43675639});
vec[1].pb({43675640, 60954347});
vec[2].pb({60954348, 64185793});
vec[0].pb({64185794, 90221630});
vec[2].pb({90221631, 91431520});
vec[1].pb({91431521, 131026919});
vec[2].pb({131026920, 135332445});
vec[0].pb({135332446, 192557381});
vec[2].pb({192557382, 196540378});
vec[1].pb({196540379, 274294562});
vec[2].pb({274294563, 288836071});
vec[0].pb({288836072, 405997337});
vec[2].pb({405997338, 411441843});
vec[1].pb({411441844, 589621136});
vec[2].pb({589621137, 608996005});
vec[0].pb({608996006, 866508215});
vec[2].pb({866508216, 884431704});
vec[1].pb({884431705, 1000000000});
}
ll dp[MAXN][4], cnt[3];

ll f(ll x){
	ll res=x*m-x*(x+1)/2;
	return res%mod;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	Build();
	cin>>n>>m;
	for (int i:{0, 1, 2}){
		for (pii p:vec[i]) if (p.first<=m) cnt[i]+=f(min(m, p.second))-f(p.first-1);
		cnt[i]%=mod;
	}
	
	dp[0][0]=1;
	for (int i=1; i<=n; i++) for (int j:{0, 1, 2, 3}) for (int k:{0, 1, 2}){
		dp[i][j]=(dp[i][j] + dp[i-1][j^k]*cnt[k])%mod;
	}
	ll ans=(dp[n][1]+dp[n][2]+dp[n][3])%mod;
	if (ans<0) ans+=mod;
	cout<<ans<<'\n';
	
	return 0;
}