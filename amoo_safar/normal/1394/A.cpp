// Zende bad Shoma nasime faghat !
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
const ll Log = 30;

ll n, d, m;

vector<ll> V1, V0;

ll ps1[N], ps0[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> d >> m;
	ll v;
	for(int i = 1; i <= n; i++){
		cin >> v;
		if(v > m) V1.pb(v);
		else V0.pb(v);
	}
	sort(all(V0)); reverse(all(V0));
	sort(all(V1)); reverse(all(V1));

	ll n1 = V1.size();
	ll n0 = V0.size();
	for(int i = 1; i <= n1; i++) ps1[i] = ps1[i - 1] + V1[i - 1];
	for(int i = 1; i <= n0; i++) ps0[i] = ps0[i - 1] + V0[i - 1];
	
	ll ans = ps0[n0];

	for(int i = 1; i <= n1; i++){
		ll rq = 1ll * (i - 1) * d;
		if(rq > (n - i)) break;
		ll d2 = min(rq, n1 - i);
		rq -= d2;
		//cerr << i << ' ' << ps1[i] << ' ' << rq << '\n';
		ans = max(ans, ps1[i] + ps0[n0 - rq]);
	}
	cout << ans << '\n';
	return 0;
}