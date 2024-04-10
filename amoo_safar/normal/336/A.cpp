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
	ll x, y;
	cin >> x >> y;
	ll s = abs(x) + abs(y);
	pll a = {0, s};
	if(y < 0) a.S = -s;
	pll b = {s, 0};
	if(x < 0) b.F = -s;
	if(a > b) swap(a,b);
	cout << a.F << " " << a.S << " " << b.F << " " << b.S << '\n';
	return 0;
}