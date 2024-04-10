#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

const int MOD = 1e9 + 7;

int mul(ll a, ll b) {
	if (!b)
		return 0;
	if (b % 2) 
		return (mul(a, b - 1) + a) % MOD;
	int t = mul(a, b / 2);
	return (t + t) % MOD;
}

int solve(ll n) {
	ll odd = 0, even = 0, deg = 1;
	bool f = 1;
	for (ll i = 0; i <= n; i += deg, deg *= 2) {
		if (f) 
			odd += min(deg, n - i);
		else 
			even += min(deg, n - i);
		f ^= 1;
	}
	return (mul(odd, odd) + mul(even, even + 1)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll l, r;
    cin >> l >> r;
    cout << (solve(r) - solve(l - 1) + MOD) % MOD;
    return 0;
}