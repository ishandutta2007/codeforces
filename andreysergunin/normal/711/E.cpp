#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <tuple>
#include <unordered_map>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fs first
#define sc second

const int P = 1e6 + 3;

long long binPow(long long a, long long b, int m) {
	if (b == 0)
		return 1;
	long long x = binPow(a, b / 2, m);
	x *= x;
	x %= m;
	if (b & 1)
		x = x * a % m;
	return x;
}

int main() {	
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	long long n, k;
	cin >> n >> k;
	if (n < 60 && (1ll << n) < k) {
		cout << 1 << " " << 1 << endl;
		return 0;
	}

	long long q = binPow(2, (n % (P - 1)) * (k % (P - 1)), P);
	
	long long r = binPow(2, P - 2, P);

	long long d = n;
	for (long long l = 2; l < k; l *= 2)
		d += (k - 1) / l;

	q *= binPow(r, d, P);
	q %= P;

	if (k >= P) {
		cout << q << " " << q << endl;
		return 0;
	}

	long long x = binPow(2, n, P);

	long long p = 1;
	for (int i = 0; i < k; ++i) {
		p *= (x - i);
		p %= P;
	}
	p *= binPow(r, d, P);
	p %= P;
	p = q - p + P;
	p %= P;
	cout << p << " " << q << endl;
	return 0;
}