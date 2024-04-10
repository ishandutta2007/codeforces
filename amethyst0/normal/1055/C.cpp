#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

ll inter(ll l1, ll r1, ll l2, ll r2) {
	l1 = max(l1, l2);
	r1 = min(r1, r2);

	if (r1 < l1) {
		return 0;
	}

	return r1 - l1 + 1;
}

ll solve(ll la, ll ra, ll ta, ll lb, ll rb, ll tb) {
	ll x = la - lb;
	x %= tb;

	if (x < 0) {
		x += tb;
	}

	ll y = ta;

	ll g = gcd(y, tb);

	ll f = x - x / g * g;

	return inter(la, ra, la - f, la - f + (rb - lb));
}

int main() {
	int la, ra, ta, lb, tb, rb;

	cin >> la >> ra >> ta >> lb >> rb >> tb;

	cout << max(solve(la, ra, ta, lb, rb, tb), solve(lb, rb, tb, la, ra, ta)) << endl;

	//system("pause");
}