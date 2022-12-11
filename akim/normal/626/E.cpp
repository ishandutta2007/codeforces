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
const int maxn = 200100;

ll a[maxn], pf[maxn];

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

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(&a[0], &a[n]);
	for(int i = 0; i < n; i++) {
		pf[i] = (i ? pf[i - 1] : 0) + a[i];
	}
	long double ans = -1.;
	int pos = -1, cnt = -1;
	for(int i = 0; i < n; i++) {
		int l = 0, r = min(i, n - i - 1);
		while(l < r) {
			int m = (l + r) >> 1;
			double v1 = (pf[i] - pf[i - 1 - m] + pf[n - 1] - pf[n - 1 - m]) / (m * 2. + 1.) - a[i];
			m++;
			double v2 = (pf[i] - pf[i - 1 - m] + pf[n - 1] - pf[n - 1 - m]) / (m * 2. + 1.) - a[i];
			if(v1 < v2) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		if(ans < (pf[i] - pf[i - 1 - l] + pf[n - 1] - pf[n - 1 - l]) / (l * 2. + 1.) - a[i]) {
			ans = (pf[i] - pf[i - 1 - l] + pf[n - 1] - pf[n - 1 - l]) / (l * 2. + 1.) - a[i];
			pos = i;
			cnt = l;
		}
	}

	printf("%d\n", cnt * 2 + 1);
	for(int i = 0; i < n; i++) {
		if(pos - cnt <= i && pos >= i) {
			printf("%lld ", a[i]);
		}
		if(n - cnt <= i && n > i) {
			printf("%lld ", a[i]);
		}
	}

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