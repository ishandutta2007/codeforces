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
const int maxn = 1000100;

int v[maxn], c[maxn], dp[maxn];
ll cnt[maxn];

multiset<int> fset, sset;

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

	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		v[i] *= 100;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	for(int i = n - 1, j = n - 1; i >= 0; i--) {
		fset.insert(v[i]);
		sset.insert(c[i]);
		while(j > i) {
			int ans1 = min(*fset.rbegin(), *sset.begin());
			fset.erase(fset.find(v[j]));
			sset.erase(sset.find(c[j]));
			int ans2 = min(*fset.rbegin(), *sset.begin());
			if(ans2 < ans1) {
				fset.insert(v[j]);
				sset.insert(c[j]);
				break;
			} else {
				j--;
			}
		}
		dp[i] = min(*fset.rbegin(), *sset.begin());
	}

	sort(&dp[0], &dp[n]);

	double ans = 0., val = (k * 1.) / (n * 1.);
	ans = dp[0] * val;
	for(int i = n - 1; i >= k; i--) {
		val *= (n - k - (n - 1 - i) * 1.) / (i * 1.);
		ans += dp[n - i] * val;
	}

	printf("%.10lf", ans);

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