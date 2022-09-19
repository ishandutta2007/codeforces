// That's How much we have in common
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
	ll n, k;
	for(int i = 1; i <= T; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}
		ll ans = 0;
		for(int j = 0; j + 1 < n; j++){
			if(a[j] > a[j + 1])
				ans += a[j] - a[j + 1];
		}
		cout << ans << '\n';
	}
	return 0;
}