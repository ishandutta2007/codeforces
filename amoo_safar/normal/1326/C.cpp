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

const ll Mod = 998244353;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll v;
	ll fl = 0;
	ll ans = 1;
	ll sm = 0;
	ll cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> v;
		if(v > n - k){
			if(fl) ans = (ans * cnt) % Mod;
			fl = 1;
			cnt = 1;
			sm += v;
		} else cnt ++;
	}
	cout << sm << " " << ans << '\n';

	return 0;
}