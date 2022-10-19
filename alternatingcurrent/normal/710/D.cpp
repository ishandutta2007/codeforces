#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef __int128 lll;
lll qabs(lll a){
	return (a >= 0) ? a : -a;
}
lll ceildiv(lll n, lll d){
	return n / d + ((n > 0) && (n % d != 0));
}
lll floordiv(lll n, lll d){
	return n / d - ((n < 0) && (n % d != 0));
}

lll a1, b1, a2, b2, L, R;
lll exgcd(lll a, lll b, lll &x, lll &y){
	if(!a){ x = 0, y = 1; return b; }
	if(!b){ x = 1, y = 0; return a; }
	lll g = exgcd(b % a, a, y, x);
	x -= (b / a) * y;
//	cout << a << "*" << x << " + " << b << "*" << y << " = " << g << endl;
	return g;
}

ll readint(){
	ll a; cin >> a;
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	a1 = readint(), b1 = readint();
	a2 = readint(), b2 = readint();
	L = readint(), R = readint();
	lll k0, l0;
	lll g = exgcd(a1, -a2, k0, l0);
	if(g < 0)
		k0 = -k0, l0 = -l0, g = -g;
//	cout << k0 << " " << l0 << " " << g << endl;
	if((b2 - b1) % g != 0){
		cout << "0\n";
		return 0;
	}
	k0 *= (b2 - b1) / g, l0 *= (b2 - b1) / g;
//	cout << k0 << " + " << (a2 / g) << "i\n";
//	cout << l0 << " + " << (a1 / g) << "i\n";
	lll lb = max({ceildiv(-k0, (a2 / g)), ceildiv(-l0, (a1 / g)), ceildiv(L - a1 * k0 - b1, a1 * a2 / g)});
	lll ub = floordiv(R - b1 - a1 * k0, a1 * a2 / g);
//	cout << lb << " " << ub << endl;
	cout << max(0ll, (ll)(ub - lb + 1)) << endl;
	return 0;
}