#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 61;

ll mk[N];
ll K=4;
ll wht(ll x, ll y, ll z){
	return 1000000*(x&K) + 1000*(y&K) + (z&K);
}

vector<ll> V;
vector<pll> A;


ll dp[Log + 3];
ll d[Log + 3];
ll d1[4][3] = {{0,0,0},
				{1,0,1},
				{0,1,1},
				{1,1,0}};

ll d2[4][3] = {{0,0,0},
				{0,1,1},
				{1,1,0},
				{1,0,1}};
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	dp[0] = 0;
	for(int i = 1; i < Log; i++) dp[i] = dp[i - 1] + (i & 1 ? 0 : 1ll<<(i-2));
	for(int i = 0; i < Log; i++) d[i] = (1ll << (i-(i&1)));
	
	//for(int i = 0; i < Log; i++) cerr << dp[i] << " " << d[i] << '\n';
	
	ll T;
	cin >> T;
	//cout << '\n';
	while(T--){
		ll n;
		cin >> n;
		//n= 20 - T;
		ll r = (n - 1) / 3;
		ll ty = ((n-1) % 3);
		r += 1;
		ll rr;
		ll ans = 0;
		for(int i = 0; i < Log; i += 2){
			rr = r;
			ll fl = 0;
			if(rr <= dp[i]){
				fl = 0;
			} else {
				rr-=dp[i];
				if(rr <= d[i]){
					if(ty != 1) fl = 1;
				} else {
					rr -= d[i];

					fl = d1[((rr - 1)%(4*d[i]))/d[i]][ty];
				}
			}
			//cerr << fl << " " << i << '\n';
			ans |= (fl * (1ll << i));
		}
		//ll ans = 0;
		for(int i = 1; i < Log; i += 2){
			rr = r;
			ll fl = 0;
			if(rr <= dp[i]){
				fl = 0;
			} else {
				rr-=dp[i];
				if(rr <= d[i]){
					if(ty != 0) fl = 1;
				} else {
					rr -= d[i];
					fl = d2[((rr - 1)%(4*d[i]))/d[i]][ty];
				}
			}
			
			ans |= (fl * (1ll << i));
		}
		cout << ans << '\n';
	}
	return 0;
}