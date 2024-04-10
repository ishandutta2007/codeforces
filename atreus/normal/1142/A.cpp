#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 1e5 + 10;
const ll inf = 1e18;

ll b;

ll n, k;

ll mnm = inf, mxm = 0;

ll gcd(ll a, ll b){
	if (a > b)
		swap(a, b);
	if (a == 0)
		return b;
	if (b % a == 0)
		return a;
	return gcd(b % a, a);
}

void update(ll x){
	x = (n * k) / x;
	mnm = min(mnm, x);
	mxm = max(mxm, x);
}

ll dis(ll fr, ll to){
	if (to >= fr)
		return to - fr;
	else
		return n * k - (fr - to);
}

void solve(ll st){
	for (int i = 0; i < n; i++){
		ll p = i * k + b;
		ll len = dis(st, p);
		ll m = gcd(len, n * k);
		update(m);
		ll q = (i + 1) * k - b;
		len = dis(st, q);
		m = gcd(len, n * k);
		update(m);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	ll a;
	cin >> a >> b;
	solve(a);
	solve(k - a);
	cout << mnm << " " << mxm << endl;
}