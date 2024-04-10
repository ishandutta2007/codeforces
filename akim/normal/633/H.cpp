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
const int maxn = 30100;

pair<ll, int> a[maxn];
ll fib[maxn];

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

	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &a[i].fs);
		a[i].sc = i + 1;
	}
	sort(&a[0], &a[n]);

	fib[0] = fib[1] = 1;
	for(int i = 2; i < n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] -= fib[i] >= m ? m : 0;
	}


	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		ll ans = 0;
		int l, r, lst = -1;
		scanf("%d%d", &l, &r);
		for(int j = 0, k = 0; j < n; ++j) {
			if(a[j].sc >= l && a[j].sc <= r && a[j].fs != lst) {
				lst = a[j].fs;
				ans += fib[k++] * a[j].fs;
			}
		}
		ans %= m;
		printf("%lld\n", ans);
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