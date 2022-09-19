// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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

vector<pll> V;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x = 0, y = 0, k;
	cin >> k;
	V.pb({x, y});
	for(int i = 0; i <= k; i++){
		V.pb({x + 1, y});
		V.pb({x + 1, y + 2});
		V.pb({x, y + 1});
		V.pb({x, y + 2});
		V.pb({x + 2, y});
		V.pb({x + 2, y + 1});
		V.pb({x + 2, y + 2});
		x += 2;
		y += 2;
	}
	cout << V.size() << '\n';
	for(auto x : V) cout << x.F << ' ' << x.S << '\n';
	return 0;
}