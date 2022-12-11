#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;



int main() {

	#ifdef SOL
	{
//		freopen("input.txt", "r", stdin);
//		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	ll n;
	scanf("%lld", &n);
	if(n == 0) {
		cout << "0 0";
		return(0);
	}

	ll i = 0, sum = 0;
	ll l = 0, r = 1000000010;
	while(l + 1 < r) {
		ll m = (l + r) >> 1;
		if(((m * (m - 1)) >> 1) * 6 < n) {
			l = m;
		} else {
			r = m;
		}
	}
	i = l;
	n -= ((i * (i - 1)) >> 1) * 6;
	n--;
	ll x = 2 * i - 1, y = 2;
	if(n >= i - 1) {
		n -= i - 1;
		x += -1 * (i - 1);
		y += 2 * (i - 1);
	} else {
		x += -1 * (n);
		y += 2 * (n);
		n = 0;
	}
	if(n >= i) {
		n -= i;
		x += -2 * (i);
		y += 0 * (i);
	} else {
		x += -2 * (n);
		y += 0 * (n);
		n = 0;
	}
	if(n >= i) {
		n -= i;
		x += -1 * (i);
		y += -2 * (i);
	} else {
		x += -1 * (n);
		y += -2 * (n);
		n = 0;
	}

	if(n >= i) {
		n -= i;
		x += 1 * (i);
		y += -2 * (i);
	} else {
		x += 1 * (n);
		y += -2 * (n);
		n = 0;
	}

	if(n >= i) {
		n -= i;
		x += +2 * (i);
		y += 0 * (i);
	} else {
		x += +2 * (n);
		y += 0 * (n);
		n = 0;
	}

	if(n >= i) {
		n -= i;
		x += 1 * (i);
		y += +2 * (i);
	} else {
		x += 1 * (n);
		y += +2 * (n);
		n = 0;
	}

	cout << x << " " << y << endl;

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Andrey Kim