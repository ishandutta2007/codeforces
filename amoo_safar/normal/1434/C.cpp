// I'll Crush you !
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


ll f(ll x){
	return (x+ 1) * x / 2ll;
}
int Main(){
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll bl = c/d;
	ll rm = c%d;

	ll X = bl * d + rm;
	X *= b;
	if(X-a < 0)
		return cout << "-1\n",0;

	//debug(bl);
	//debug(rm);
	ll cnt = a / (d * b);
	cnt = min(cnt, bl);

	cout << (cnt + 1) * a - ((d*b) * (f(cnt))) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) Main();
	return 0;
}