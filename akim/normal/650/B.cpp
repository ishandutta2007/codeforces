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
const int maxn = 500100;

ll dp[maxn], pd[maxn], dp1[maxn], pd1[maxn];

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

	int n, a, b, t;
	scanf("%d%d%d%d\n", &n, &a, &b, &t);
	string s;
	getline(cin, s); s.pb(s[0]);
	dp[0] = 1 + (s[0] == 'w') * b;
	for(int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + a + 1 + (s[i] == 'w') * b;
	}
	pd[n - 1] = 1 + (s[n - 1] == 'w') * b;
	for(int i = n - 2; i >= 0; i--) {
		pd[i] = pd[i + 1] + a + 1 + (s[i] == 'w') * b;
	}
	dp1[1] = 1 + (s[1] == 'w') * b;
	for(int i = 2; i <= n; i++) {
		dp1[i] = dp1[i - 1] + a + 1 + (s[i] == 'w') * b;
	}
	pd1[n] = 1 + (s[n] == 'w') * b;
	for(int i = n - 1; i >= 1; i--) {
		pd1[i] = pd1[i + 1] + a + 1 + (s[i] == 'w') * b;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(dp[i] <= t) {
			ans = max(ans, i + 1);
		}
		if((dp[i] + (i + 1) * a) <= t) {
			int l = i, r = n;
			while(l + 1 < r) {
				int m = (l + r) / 2;
				if(dp[i] + (i + 1) * a + pd[m] <= t) {
					r = m;
				} else {
					l = m;
				}
			}
			ans = max(ans, i + 1 + n - r);
		}
	}
	for(int i = n; i >= 1; i--) {
		if(pd1[i] <= t) {
//			ans = max(ans, n - i + 1);
		}
		if((pd1[i] + (n - i + 1) * a) <= t) {

			int l = 0, r = i;
			while(l + 1 < r) {
				int m = (l + r) / 2;
				if(pd1[i] + (n - i + 1) * a + dp1[m] <= t) {
					l = m;
				} else {
					r = m;
				}
			}
//			cout << n - i + 1 << " " << l << " " << pd1[i] << " " << dp1[l] << endl;
			ans = max(ans, n - i + 1 + l);
		}
	}

	printf("%d", ans);

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