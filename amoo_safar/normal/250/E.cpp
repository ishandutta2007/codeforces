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

str s[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = '#' + s[i] + '#';
		//cout << s[i] << '\n';
	}
	ll x = 1, y = 1, d = 1;
	ll L = 1, R = 1;
	ll ans = 0;
	ll oo = 60000000;
	ll it = 0;
	while(y != n && it < oo){
		//cerr << x << " " << y << " " << d << '\n';
		//R = x;
		//L = x;
		it ++;
		if(d == 1){
			if(x < R){
				ans += R - x;
				x = R;
			}
			if(s[y + 1][x] == '.'){
				ans ++;
				y ++;
				L = x;
				R = x;
				continue;
			}
			if(s[y][x + 1] == '.'){
				R ++;
				x ++;
				ans ++;
				continue;
			}
			if(s[y][x + 1] == '+') s[y][x + 1] = '.';
			d = 1 - d;
			ans ++;
		} else {
			if(x > L){
				ans += x - L;
				x = L;
			}
			if(s[y + 1][x] == '.'){
				ans ++;
				y ++;
				L = x;
				R = x;
				continue;
			}
			if(s[y][x - 1] == '.'){
				L --;
				x --;
				ans ++;
				continue;
			}
			if(s[y][x - 1] == '+') s[y][x - 1] = '.';
			d = 1 - d;
			ans ++;
		}
	}
	if(it >= oo) cout << "Never\n";
	else cout << ans << '\n';
	return 0;
}