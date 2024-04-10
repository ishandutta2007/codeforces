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
	ll T;
	cin >> T;
	while(T--){
		ll n;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		ll mx = 0;
		ll m = a[0];
		for(int i = 1; i < n; i++){
			mx = max(mx, m - a[i]);
			m = max(m, a[i]);
		}
		for(int i = 0; i < 60; i++){
			if(mx < (1ll << i)){
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}