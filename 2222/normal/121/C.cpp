#include <algorithm>
#include <iostream>
#include <assert.h>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, k;
int p[13];

bool islucky(int x) {
	return x ? (x % 10 == 4 || x % 10 == 7) && islucky(x / 10) : true;
}

int go(ll x) {
	if (x > n) return 0;
	int res = go(x * 10 + 4) + go(x * 10 + 7);
	if (x >= n - 12) {
		res += islucky(n - 12 + p[x - (n - 12)]);
	} else {
		++res;
	}
	return res;
}

int main() {
	cin >> n >> k;
	REP (i, 13) p[i] = i;
	--k;
	if (n <= 13) {
		ll t = 1;
		REP (i, n) t *= i + 1;
		if (k >= t) {
			puts("-1");
			return 0;
		}
	}
	for (int i = 12; i >= 0; --i) {
		sort(p, p + i + 1);
		ll z = 1;
		REP (j, i) z *= j + 1;
		swap(p[i], p[k / z]);
		k %= z;
	}
	reverse(p, p + 13);
	cout << go(4) + go(7) << endl;
	return 0;
}