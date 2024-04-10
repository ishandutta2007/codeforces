// vaziat meshki-ghermeze !
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

ll C2(ll x){
	return x * (x - 1) / 2ll;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	str s;
	cin >> s;
	int n = s.size();

	ll x, y;
	cin >> x >> y;
	vector<ll> V;
	ll c0 = 0, s0 = 0;
	ll c1 = 0, s1 = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '0'){
			c0 ++;
			s0 += i;
		} else if(s[i] == '1'){
			c1 ++;
			s1 += i;
		} else {
			V.pb(i);
		}
	}

	ll ans = Inf;
	int m = V.size();
	vector<ll> ps(m + 1);
	ps[0] = 0;
	for(int i = 1; i <= m; i++)
		ps[i] = ps[i - 1] + V[i - 1];


	for(int i = 0; i <= m; i++){
		ll A = ps[i];
		ll B = ps[m] - ps[i];

		ans = min(ans, y * (s0 + A - C2(i + c0)) + x * (s1 + B - C2(m - i + c1))) ;
		
		ans = min(ans, y * (s0 + B - C2(m - i + c0)) + x * (s1 + A - C2(i + c1))) ;
		
	}
	cout << ans << '\n';
	return 0;
}