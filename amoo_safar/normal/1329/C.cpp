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
const int N = 3e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


ll a[N];
vector<ll> A;

ll Solve(){
	//memset(a, 0, sizeof a);
	A.clear();
	ll h, g;
	cin >> h >> g;
	ll n = (1 << h) - 1;
	fill(a, a + n + n + 4, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll m = (1 << g) - 1;
	for(int i = 1; i <= m;){
		ll x = i;
		while(a[x + x] + a[x + x + 1] > 0){
			if(a[x + x] > a[x + x + 1]) x = 2*x;
			else x = 2*x + 1;
		}
		if(x <= m){
			i++;
			continue;
		}
		A.pb(i);
		x = i;
		while(a[x + x] + a[x + x + 1] > 0){
			if(a[x + x] > a[x + x + 1]){
				x = 2*x;
			} else {
				x = 2*x + 1;
			}
			swap(a[x], a[x / 2]);
		}
		a[x] = 0;
	}
	ll s = 0;
	for(int i = 1; i <= m; i++) s += a[i];
		cout << s << '\n';
	for(auto x : A) cout << x << ' ';
		cout << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while(t--) Solve();
	return 0;
}