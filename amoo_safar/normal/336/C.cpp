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

ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int l = 31; l >= 0; l--){
		ll ans = -1;
		for(int i = 1; i <= n; i++){
			if(a[i] >> l & 1) {
				if(ans == -1) ans = a[i];
				ans &= a[i];
			}
		}
		if(ans == -1) continue;
		if(ans % (1ll << l)) continue;

			vector<ll> V;
			for(int i = 1; i <= n; i++){
				if(a[i] >> l & 1) {
					V.pb(a[i]);
				}
			}	
			cout << V.size() << '\n';
			for(auto x : V) cout << x << ' ';
			return 0;
		
	}
	return 0;
}