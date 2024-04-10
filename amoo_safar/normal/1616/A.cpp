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
typedef pair<int, int> pii;

const int Mod = 1000000007LL;
const int N = 2e5 + 10;
const int Log = 30;
const ll Inf = 2242545357980376863LL;

int Main(){
	map<ll, ll> mp;
	ll n;
	cin >> n;
	for(int i =0 ; i < n; i++){
		ll v;
		cin >> v;
		mp[abs(v)] ++;
	}
	mp[0] = min(mp[0], 1ll);
	ll ans = 0;
	for(auto [x, y] : mp) ans += min(y, 2ll);

	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc = 1;
	cin >> tc;
	while(tc --) Main();
	return 0;
}