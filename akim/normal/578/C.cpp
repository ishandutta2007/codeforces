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

int a[2 * maxn];
int n;

long double check(long double m) {
	long double ret = 0, mx = 0, mn = 0, ps = 0;
	for(int i = 0; i < n; i++) {
		ps += a[i] * 1. - m;
		ret = max(ret, max(abs(ps - mx), abs(ps - mn)));
		mx = max(mx, ps);
		mn = min(mn, ps);
	}
	return(ret);
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	long double l = -3. * (1e9), r = 3. * (1e9);
	for(int i = 0; i < 220; i++) {
		long double m1 = l + (r - l) / 3., m2 = r - (r - l) / 3.;
		if(check(m1) < check(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}

	printf("%.10lf", (double)check(l));

	return(0);
}

// by Kim Andrey