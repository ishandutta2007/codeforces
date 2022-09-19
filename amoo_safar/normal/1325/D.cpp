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

ll ans[4];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll x, s;
	cin >> x >> s;
	if(x + s == 0) return cout << 0, 0;
	if(x > s || (x + s) % 2 == 1) return cout << -1, 0;
	if(x == s) return cout << "1\n" << x, 0;
	ll an = (s - x) / 2;
	if( (an ^ (s - an)) == x) return cout << "2\n" << an << " " << s - an << '\n', 0;
	cout << "3\n" << x << " " << an << " " << an << '\n';
	return 0;
}