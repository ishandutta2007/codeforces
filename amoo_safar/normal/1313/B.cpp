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

ll a[3];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	for(int i = 0; i < T; i++){
		ll n, x, y;
		cin >> n >> x >> y;
		ll a = x - 1;
		ll b = y - 1;
		ll c = n - x;
		ll d = n - y;
		ll cnt = 0;
		ll T = max(0ll, min(d - 1, a));
		a -= T;
		d -= T;
		cnt += T;
		T = max(0ll, min(c - 1, b));
		b -= T;
		c -= T;
		cnt += T;
		cnt += min(c, d);
		cout << n - min(n - 1, cnt) << " " << min(n- 1 ,(x-1)+(y-1)) + 1 << '\n';
	}
	return 0;
}