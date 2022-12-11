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
const int maxn = 5050;

ll a[maxn];

ll all[maxn], dp[maxn];

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
		for(int j = i + 1; j < n; j++) {
			all[a[j] - a[i]]++;
		}
	}

	for(int i = 0; i < maxn; i++) {
		for(int j = 0; j < maxn; j++) {
			if(i + j >= maxn) break;
			dp[i + j] += all[i] * all[j];
		}
	}

	ll cnt = 0;

	for(int i = 1; i < maxn; i++) {
		dp[i] += dp[i - 1];
		cnt += all[i] * dp[i - 1];
	}
	ll allc = (n * (n - 1) / 2ll) * 1ll * (n * (n - 1) / 2ll) * 1ll * (n * (n - 1) / 2ll);
	printf("%.10lf", (cnt * 1.) / (allc * 1.));

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