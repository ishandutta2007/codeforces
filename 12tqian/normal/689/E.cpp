#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
static long track[200005];
static long binom[200005];
static long MOD = 1000000007;
const long MAX = 200005;
static long l[MAX];
static long r[MAX];
int mulmod(long a, long b)
{
	long res = 0; // Initialize result
	a = a % MOD;
	while (b > 0)
	{
		// If b is odd, add 'a' to result
		if (b % 2 == 1)
			res = (res + a) % MOD;

		// Multiply 'a' with 2
		a = (a * 2) % MOD;

		// Divide b by 2
		b /= 2;
	}

	// Return result
	return res % MOD;
}
long modInverse(long a, long m)
{
	long m0 = m;
	long y = 0, x = 1;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		// q is quotient
		long q = a / m;
		long t = m;

		// m is remainder now, process same as
		// Euclid's algo
		m = a % m, a = t;
		t = y;

		// Update y and x
		y = x - q * y;
		x = t;
	}

	// Make x positive
	if (x < 0)
		x += m0;

	return x;
}
int main() {
	long n, k;

	scanf("%d %d", &n, &k);
	for (long i = 0; i<n; i++) {
		long a, b;
		scanf("%d %d", &a, &b);
		l[i] = a;
		r[i] = b;
	}
	for (long i = k; i <= n; i++) {
		if (i == k) {
			binom[i] = 1;
		}
		else {
			binom[i] = mulmod(binom[i - 1], i) %MOD;
			binom[i] = mulmod(binom[i], modInverse(i - k, MOD))% MOD;

		}
	}

	sort(r, r + n);
	sort(l, l + n);
	l[n] = 2000000000;
	long c = 0;
	long a = 0;
	long b = 0;
	long rr = min(l[a], r[b]);
	int cheat = 0;
	long preva = -1;
	long prevb = -1;
	while (b < n) {
        if(a == preva && b == prevb){
            cheat += 1;
        }
        preva = a;
        prevb = b;
        if(cheat >=1000){
            break;
        }
		if (a == 0) {
			long x = l[a];
			while (l[a] == x && a < n) {
				c += 1;
				a += 1;
			}
			a -= 1;
			track[c] += 1;
			track[c] = track[c] % MOD;
			rr = l[a];
			a += 1;
		}
		else if (l[a]< r[b] && a<n) {
			long x = l[a];
			track[c] += (l[a] - rr - 1) % MOD;
			track[c] = track[c] % MOD;
			while (l[a] == x && a < n) {
				c += 1;
				a += 1;
			}
			a -= 1;
			track[c] += 1;
			track[c] = track[c] % MOD;
			rr = l[a];
			a += 1;
		}
		else if (l[a] > r[b]) {
			long x = r[b];
			track[c] += (r[b] - rr) % MOD;
			track[c] = track[c] % MOD;
			while (r[b] == x && b < n) {
				b += 1;
				c -= 1;
			}
			b -= 1;
			rr = r[b];
			b += 1;
		}
		else if(l[a] == r[b]) {
			long x = l[a];
			track[c] += (l[a] - rr - 1)%MOD;
			track[c] = track[c]%MOD;
			while (l[a] == x && a < n) {
				c += 1;
				a += 1;
			}
			track[c] += 1;
			track[c] = track[c] % MOD;
			while (r[b] == x && b < n) {
				c -= 1;
				b += 1;
			}
			rr = x;
		}
	}
	long total = 0;
	for (long i = k; i <= n; i++) {
		long toAdd = mulmod(binom[i], track[i]);
		total += (toAdd%MOD);
		total = total % MOD;
	}
	cout << total << endl;
	return 0;
}