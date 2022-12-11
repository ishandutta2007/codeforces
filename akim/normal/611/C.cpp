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

char c[550][550];
int dw[550][550], rg[550][550];

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
	for(int i = 0; i < n; i++) {
		scanf("\n");
		for(int j = 0; j < m; j++) {
			c[i][j] = getchar();
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(c[i][j] == '.' && c[i + 1][j] == '.') {
				dw[i][j] = 1;
			}
			dw[i][j] += (i - 1 >= 0 ? dw[i - 1][j] : 0) + (j - 1 >= 0 ? dw[i][j - 1] : 0) -  ((i - 1 >= 0 && j - 1 >= 0) ? dw[i - 1][j - 1] : 0);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(c[i][j] == '.' && c[i][j + 1] == '.') {
				rg[i][j] = 1;
			}
			rg[i][j] += (i - 1 >= 0 ? rg[i - 1][j] : 0) + (j - 1 >= 0 ? rg[i][j - 1] : 0) -  ((i - 1 >= 0 && j - 1 >= 0) ? rg[i - 1][j - 1] : 0);
		}
	}

	int q;
	scanf("%d", &q);
	for(; q > 0; q--) {
		int r1, r2, c1, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--, r2--, c1--, c2--;
		int ans = 0;
//		cout << "--- " << r1 << "";
		if(r2 - 1 >= 0) {
			ans += dw[r2 - 1][c2];
//			cout << dw[r2 - 1][c2] << endl;
		}
		if(r1 - 1 >= 0) {
			ans -= dw[r1 - 1][c2];
//			cout << dw[r1 - 1][c2] << endl;
		}
		if(r2 - 1 >= 0 && c1 - 1 >= 0) {
			ans -= dw[r2 - 1][c1 - 1];
//			cout << dw[r2 - 1][c1 - 1] << endl;
		}
		if(r1 - 1 >= 0 && c1 - 1 >= 0) {
			ans += dw[r1 - 1][c1 - 1];
//			cout << dw[r1 - 1][c1 - 1] << endl;
		}

		if(c2 - 1 >= 0) {
			ans += rg[r2][c2 - 1];
		}
		if(c1 - 1 >= 0) {
			ans -= rg[r2][c1 - 1];
		}
		if(c2 - 1 >= 0 && r1 - 1 >= 0) {
			ans -= rg[r1 - 1][c2 - 1];
		}
		if(c1 - 1 >= 0 && r1 - 1 >= 0) {
			ans += rg[r1 - 1][c1 - 1];
		}

		printf("%d\n", ans);
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