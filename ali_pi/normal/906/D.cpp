#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, nT, t[1<<17], w[1<<17], Q;
int l, r;

ll mul(ll a, ll b, ll m) { return a*b >= m ? a*b%m + m : a*b; }

ll mpow(ll b, ll exp, ll m) {
	ll r = 1;
	while (exp) {
		if (exp & 1) r = mul(r,b,m);
		b = mul(b,b,m);
		exp /= 2;
	}
	return r;
}

int phi(int n) {
	int r = n;
	for (int i = 2; i <= n; ++i) {
		if (n % i) continue;
		r = (r / i) * (i-1);
		while (!(n % i)) n /= i;
	}
	return r;
}

int main() {
	cin >> N >> t[0];
	for (int i = 0; i++ < N; ) cin >> w[i];
	for (nT = 0; t[nT] > 1; t[nT+1] = phi(t[nT]), ++nT);
	cin >> Q;
	while (Q--) {
		cin >> l >> r;
		ll v = 1;
		for (int i = min(nT, r - l); ~i; --i) v = mpow(w[i+l], v, t[i]);
		cout << v % t[0] << "\n";
	}
}