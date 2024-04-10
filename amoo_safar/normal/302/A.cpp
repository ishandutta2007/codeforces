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
	ll n, q;
	cin >> n >> q;
	ll v;
	ll c1 = 0;
	for(int i = 0; i < n; i++){
		cin >> v;
		c1 += (v == 1);
	}
	ll c2 = (n - c1);
	ll l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		ll ln = (r - l + 1);
		if(ln%2 == 0 && min(c1, c2) >= ln / 2) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}