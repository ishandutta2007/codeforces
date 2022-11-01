#include <bits/stdc++.h> 

using namespace std;

const int MOD = 1e9 + 7;

long long a, b;

int main (int argc, char const *argv[]) {
	cin >> a >> b;
	long long r = b * (b - 1) / 2;
	r %= MOD;
	long long s = a * (a + 1) / 2;
	s %= MOD;
	s *= b, s %= MOD;
	s += a, s %= MOD;
	r *= s, r %= MOD;
	printf("%lld\n", r);
    return 0;
}