#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll a, ll b) {
	if(!b) return 0;
	ll g = __gcd(a, b);
	ll A = a / g, B = b / g;
	ll opt = 0;
	for(ll i = 1; i * i <= A; i++)
		if(A % i == 0) {
			if(i != 1)
				opt = max(opt, (b / (i * g)) * i * g);
			if((A / i) != 1)
				opt = max(opt, (b / (A / i * g)) * (A / i * g));
		}
	return (b - opt) / g + solve(a, opt);
}

int main() {
	ll a, b;
	cin >> a >> b;
	cout << solve(a, b);
}