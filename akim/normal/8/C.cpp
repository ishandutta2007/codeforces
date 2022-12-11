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

int x[maxn], y[maxn];
int dp[1 << 24];
int pr1[1 << 24], pr2[1 << 24];

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

	int x0, y0;
	scanf("%d%d", &x0, &y0);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		x[i] -= x0, y[i] -= y0;
	}

	for(int mask = 0; mask < (1 << n); mask++) {
		dp[mask] = mod;
		pr1[mask] = mod;
		pr2[mask] = mod;
	}

	dp[0] = 0;
	for(int mask = 0; mask < (1 << n); mask++) {
		int &fr = dp[mask];
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i)) {
				continue;
			}
			int nmask = (mask | (1 << i));
			int &ans = dp[nmask];
			if(ans > fr + (sqr(x[i]) + sqr(y[i])) * 2) {
				ans = fr + (sqr(x[i]) + sqr(y[i])) * 2;
				pr1[nmask] = i;
				pr2[nmask] = mod;
			}
			for(int j = i + 1; j < n; j++) {
				if(mask & (1 << j)) {
					continue;
				}
				int nmask = (mask | (1 << i) | (1 << j));
				int &ans = dp[nmask];
				if(ans > fr + sqr(x[i]) + sqr(y[i]) + sqr(x[j]) + sqr(y[j]) + sqr(x[i] - x[j]) + sqr(y[i] - y[j])) {
					ans = fr + sqr(x[i]) + sqr(y[i]) + sqr(x[j]) + sqr(y[j]) + sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
					pr1[nmask] = i;
					pr2[nmask] = j;
				}
			}
			break;
		}
	}

	cout << dp[(1 << n) - 1] << endl;
	cout << "0 ";
	for(int i = (1 << n) - 1; i > 0;) {
		int j = i;
		cout << pr1[i] + 1 << " ";
		j ^= 1 << pr1[i];
		if(pr2[i] != mod) {
			cout << pr2[i] + 1 << " ";
			j ^= 1 << pr2[i];
		}
		cout << "0 ";
		i = j;
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