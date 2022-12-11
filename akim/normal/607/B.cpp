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
const int maxn = 550;

int a[maxn];
int dp[maxn][maxn][2];
bool was[maxn][maxn][2];

int calc(int l, int r, bool global = 0) {
	if(was[l][r][global]) return(dp[l][r][global]);
	if(r - l <= 0) {
		return(1);
	}
	was[l][r][global] = 1;
	int &ans = dp[l][r][global];
	ans = mod;
	if(a[l] == a[r]) ans = min(ans, calc(l + 1, r - 1, 1));
	for(int i = l; i < r; i++) {
		ans = min(ans, calc(l , i, 0) + calc(i + 1, r, 0) + global);
		ans = min(ans, calc(l , i, global) + calc(i + 1, r, 0));
		ans = min(ans, calc(l , i, 0) + calc(i + 1, r, global));
	}
	return(ans);
}

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
		cin >> a[i];
	}

	cout << calc(0, n - 1);

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