#include <stdio.h>
typedef long long ll;
ll sq(ll v) { return v*v; }
int main() {
    ll a, b;
	scanf("%lld%lld", &a, &b);
	ll n = (a < b) ? a : b;
	if(a == 0) {
		printf("%lld\n", -sq(b));
		for(ll i = 0; i < b; i++) putchar('x');
	}else if(b == 0) {
		printf("%lld\n", sq(a));
		for(ll i = 0; i < a; i++) putchar('o');
        }else {
		ll res = -sq(a + b);
		ll res_p, res_q;
		for(ll q = 1; q <= b; q++)  for(ll p = (q>1)?(q-1):1; p <= a && p <= q; p++) {
			ll positive = sq(a - (p-1)) + (p-1);
			ll negative = sq(b / q + 1) * (b % q) + sq(b / q) * (q - b % q);
			if(res < positive - negative) {
				res = positive - negative;
				res_p = p; res_q = q;
			}
		}
		
		printf("%lld\n", res);
		for(ll i = 0; i < res_q; i++) {
			int ll = (i < b % res_q) ? (b / res_q + 1) : (b / res_q);
			for(int x = 0; x < ll; x++) putchar('x');
			int wl = (i > 0) ? 1 : a - (res_p-1);
			if(i < res_p) for(int x = 0; x < wl; x++) putchar('o');
		}
	}
    return 0;
}