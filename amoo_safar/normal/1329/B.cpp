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


ll Solve(ll d, ll m){
	if(d == 0) return 0;
	int idx = -1;
	for(int i = 0; i < 31; i++){
		if(d >> i & 1) idx = i;
	}
	ll A = Solve((1ll << idx) - 1, m);
	ll C = d - ((1ll << idx) - 1);
	ll ans = A + C + (A * C);
	ans %= m;

	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		cout << Solve(x, y) << '\n';
	}
	return 0;
}