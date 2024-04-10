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

int mx[100][100];
int sdr[100], sdc[100];
pair<pair<int, int>, pair<int, int> > p[maxn];

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

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);
		if(t == 3) {
			int r, c, x;
			scanf("%d%d%d", &r, &c, &x);
			r--, c--;
			p[i] = mp(mp(t, r), mp(c, x));
		} else
		if(t == 2) {
			int c;
			scanf("%d", &c);
			c--;
			p[i] = mp(mp(t, c), mp(0, 0));
		} else {
			int r;
			scanf("%d", &r);
			r--;
			p[i] = mp(mp(t, r), mp(0, 0));
		}
	}

	reverse(&p[0], &p[q]);
	for(int i = 0; i < q; i++) {
		int t;
		t = p[i].fs.fs;
		if(t == 3) {
			int r, c, x;
			r = p[i].fs.sc;
			c = p[i].sc.fs;
			x = p[i].sc.sc;
			mx[r][c] = x;
		} else
		if(t == 2) {
			int c = p[i].fs.sc;
			int f = mx[n - 1][c];
			for(int i = n - 1; i > 0; i--) {
				mx[i][c] = mx[i - 1][c];
			}
			mx[0][c] = f;
		} else {
			int r = p[i].fs.sc;
			int f = mx[r][m - 1];
			for(int i = m - 1; i > 0; i--) {
				mx[r][i] = mx[r][i - 1];
			}
			mx[r][0] = f;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", mx[i][j]);
		}
		printf("\n");
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