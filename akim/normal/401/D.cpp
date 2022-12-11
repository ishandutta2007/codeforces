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

ll dp[1 << 18][100];

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

	string n;
	int m;
	cin >> n >> m;
	int len = n.length();
	dp[0][0] = 1;
	for(int mask = 0; mask < (1 << len); mask++) {
		for(int ost = 0; ost < m; ost++) {
			bool ok[10] = {0};
			for(int i = 0; i < len; i++) {
				if(((mask >> i) & 1) == 0) {
					if((mask == 0 && n[i] == '0') || ok[n[i] - '0']) continue;
					int nmask = mask | (1 << i);
					int nost = (ost * 10 + (n[i] - '0')) % m;
					dp[nmask][nost] += dp[mask][ost];
					ok[n[i] -'0'] = 1;
				}
			}
		}
	}
	printf("%lld", dp[(1 << len) - 1][0]);

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