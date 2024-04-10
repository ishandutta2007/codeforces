#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <complex> 
#include <ctime>
#include <cstring>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

int MAXN = 1e4;

long long s3(long long n) {
	long long l = 0, r = 1e6;
	while (r - l > 1) {
		long long x = (l + r) / 2;
		if (x * x * x >= n)
			r = x;
		else 
			l = x;
	}
	return l;
}

vector<int> b(MAXN);
vector<int> c(MAXN);

int ansk = 0;
long long ansn = 0;

void bf(long long m, long long k, int t) {
	if (m < MAXN) {
		int curk = t + b[c[m]];
		long long curn = k + c[m];
		if (curk > ansk || (curk == ansk && curn > ansn)) {
			ansn = curn;
			ansk = curk;
		}
		return;
	}
	long long l = s3(m);
	m -= l * l * l;
	bf(m, k + l * l * l, t + 1);
	m += l * l * l;
	m = l * l * l - (l - 1) * (l - 1) * (l - 1) - 1;
	bf(m, k + (l - 1) * (l - 1) * (l - 1), t + 1);
	return;
}

int main() {
	// freopen("input.txt", "r", stdin);
	long long n;
	cin >> n;

	
	for (int i = 0; i < MAXN; ++i) {
		long long k = i;
		long long l = k;
		int t = 0;
		while (k != 0) {
			for (; l * l * l > k; --l);
			k -= l * l * l;
			++t;
		}
		b[i] = t;
	}

	c[0] = 0;

	for (int i = 1; i < MAXN; ++i) 
		c[i] = (b[c[i - 1]] > b[i] ? c[i - 1] : i);

	bf(n, 0, 0);

	cout << ansk << " " << ansn << endl;
	return 0;
}