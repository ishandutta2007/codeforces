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

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll c1 = 0, c2 = 0;
	ll n;
	cin >> n;
	str s;
	cin >> s;
	for(auto c : s) c1 += (c == 'x');
	c2 = n - c1;
	cout << abs(c1-c2)/2 << '\n';
	for(auto c : s){
		if(c == 'x' && c1 > c2){
			c1 -= 2;
			cout << 'X';
		} else if(c == 'X' && c1 < c2){
			c2 -= 2;
			cout << 'x';
		} else cout << c;
	}
	return 0;
}