// nemibinam invara kasi mesl khodemono !
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

ll f(ll x, ll y){
	ll y2 = y;
	vector<pair<int, int>> V;
	for(int i = 2; i <= 100000; i++){
		int cnt = 0;
		while(y % i == 0){
			cnt ++;
			y /= i;
		}
		if(cnt){
			V.pb({i, cnt});
			//cerr << i << ", " << cnt << '\n';
		}
	}
	if(y > 1)
		V.pb({y, 1});
	ll ans = 1;
	for(auto [p, C] : V){
		ll x2 = x;
		while(x2 % y2 == 0){
			x2 /= p;
			//debug(x2);
			//debug(p);
		}
		ans = max(ans, x2);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		cout << f(x, y) << '\n';
	}
	return 0;
}