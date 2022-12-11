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
#define hash asdfasdgsa

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 5050;

int pr = 47;
int dp[maxn][maxn];
int hash[maxn], st[maxn];
string s;

void add(int *fv, int u, int val) {
	for(; u < maxn; u |= u + 1) {
		fv[u] = fv[u] + val;
		fv[u] += fv[u] >= mod ? -mod : 0;
	}
}

int get(int *fv, int u) {
	int ret = 0;
	for(; u >= 0; u &= u + 1, u--) {
		ret = ret + fv[u];
		ret += ret >= mod ? -mod : 0;
	}
	return(ret);
}

int gethash(int lf, int rg) {
	return((hash[rg] - ((lf - 1 >= 0 ? hash[lf - 1] * 1ll * st[rg - lf + 1] % mod : 0)) + mod) % mod);
}

bool compare(int l1, int r1, int l2, int r2) {
	int lf = 0, rg = r1 - l1 + 2;
	while(lf + 1 < rg) {
		int md = (lf + rg) >> 1;
		if(gethash(l1, l1 + md - 1) == gethash(l2, l2 + md - 1)) {
			lf = md;
		} else {
			rg = md;
		}
	}
	if(lf == r1 - l1 + 1) {
		return(0);
	}
	return(s[l1 + lf] > s[l2 + lf]);
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
	scanf("%d\n", &n);
	getline(cin, s);

	for(int i = 0; i < n; i++) {
		hash[i] = ((i - 1 >= 0 ? hash[i - 1] : 0) * 1ll * pr + s[i]) % mod;
		st[i] = (i - 1 >= 0 ? st[i - 1] * 1ll * pr % mod : 1);
		for(int j = 0; j < i; j++) {
			if(s[i - j] == '0') {
//				cout << "0 ";
				if(j - 1 >= 0) {
					dp[i][j] += dp[i][j - 1];
					dp[i][j] += dp[i][j] >= mod ? -mod : 0;
				}
				continue;
			}
			int l = i - j, r = i;
			if(l - 1 - j >= 0 && compare(l, r, l - 1 - j, l - 1)) {
//				add(dp[i], j, get(dp[l - 1], j));
				dp[i][j] += dp[l - 1][min(j, l - 1)];
				dp[i][j] += dp[i][j] >= mod ? -mod : 0;
//					cout << dp[l - 1][min(j, l - 1)] << " ";
			} else {
//				add(dp[i], j, get(dp[l - 1], j - 1));
				if(j - 1 >= 0) {
					dp[i][j] += dp[l - 1][min(j - 1, l - 1)];
					dp[i][j] += dp[i][j] >= mod ? -mod : 0;
//					cout << dp[l - 1][min(j - 1, l - 1)] << " ";
				} else {
//					cout << 0 << " ";
				}
			}
			if(j - 1 >= 0) {
				dp[i][j] += dp[i][j - 1];
				dp[i][j] += dp[i][j] >= mod ? -mod : 0;
			}
		}
//		cout << "1" << endl;
//		add(dp[i], i, 1);
		dp[i][i]++;
		dp[i][i] += dp[i][i] >= mod ? -mod : 0;
		if(i - 1 >= 0) {
			dp[i][i] += dp[i][i - 1];
			dp[i][i] += dp[i][i] >= mod ? -mod : 0;
		}
	}

	printf("%d", dp[n - 1][n - 1]);

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