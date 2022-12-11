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

int matrix[20][20], now[20][20], tmp[20][20], tmp1[20][20], temp[20][20];
int a[20][20];
int n, m, s, q;

vector<pair<pair<int, int>, pair<int, int> > > mom;

void add(int x, int y) {
	matrix[a[x][y]][a[x][y]] = 1;
	if(x - 1 >= 0) {
		matrix[a[x - 1][y]][a[x][y]] = 1;
	}
	if(x + 1 < n) {
		matrix[a[x + 1][y]][a[x][y]] = 1;
	}
	if(y - 1 >= 0) {
		matrix[a[x][y - 1]][a[x][y]] = 1;
	}
	if(y + 1 < m) {
		matrix[a[x][y + 1]][a[x][y]] = 1;
	}
}

void rem(int x, int y) {
	matrix[a[x][y]][a[x][y]] = 0;
	if(x - 1 >= 0) {
		matrix[a[x - 1][y]][a[x][y]] = 0;
	}
	if(x + 1 < n) {
		matrix[a[x + 1][y]][a[x][y]] = 0;
	}
	if(y - 1 >= 0) {
		matrix[a[x][y - 1]][a[x][y]] = 0;
	}
	if(y + 1 < m) {
		matrix[a[x][y + 1]][a[x][y]] = 0;
	}
}

int get(int x, int y) {
	int idx = a[x][y], ret = 0;;
	for(int i = 0; i < s; i++) {
		ret = (ret + now[i][idx]) % mod;
	}
	return(ret);
}

void umnnowtmp1() {
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < s; j++) {
			temp[i][j] = 0;
			for(int k = 0; k < s; k++) {
				temp[i][j] += (now[i][k] * 1ll * tmp1[k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}
}
void umntmptmp() {
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < s; j++) {
			temp[i][j] = 0;
			for(int k = 0; k < s; k++) {
				temp[i][j] += (tmp[i][k] * 1ll * tmp[k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}
}
void umntmp1tmp() {
	for(int i = 0; i < s; i++) {
		for(int j = 0; j < s; j++) {
			temp[i][j] = 0;
			for(int k = 0; k < s; k++) {
				temp[i][j] += (tmp1[i][k] * 1ll * tmp[k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}
}

void binpow(int b) {

	for(int i = 0; i < s; i++) {
		for(int f = 0; f < s; f++) {
			tmp[i][f] = matrix[i][f];
			tmp1[i][f] = 0;
		}
		tmp1[i][i] = 1;
	}
	while(b) {
		if(b & 1) {
			umntmp1tmp();
			for(int i = 0; i < s; i++) {
				for(int f = 0; f < s; f++) {
					tmp1[i][f] = temp[i][f];
				}
			}
		}
		umntmptmp();
		for(int i = 0; i < s; i++) {
			for(int f = 0; f < s; f++) {
				tmp[i][f] = temp[i][f];
			}
		}
		b >>= 1;
	}
	umnnowtmp1();
	for(int i = 0; i < s; i++) {
		for(int f = 0; f < s; f++) {
			now[i][f] = temp[i][f];
		}
	}
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
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

	scanf("%d%d%d", &n, &m, &q);
	s = n * m;

	{
		int idx = 0;
		for(int i = 0; i < n; i++) {
			for(int f = 0; f < m; f++) {
				a[i][f] = idx++;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int f = 0; f < m; f++) {
				add(i, f);
			}
		}
	}

	now[0][0] = 1;

	for(int i = 0; i < q; i++) {
		int tp, x, y, z;
		scanf("%d%d%d%d", &tp, &x, &y, &z);
		x--, y--;
		mom.pb(mp(mp(z - (tp == 2), tp), mp(x, y)));
	}
	int t = 1;
	for(int i = 0; i < q; i++) {
			binpow(mom[i].fs.fs - t);
		if(mom[i].fs.sc == 1) {
			printf("%d\n", get(mom[i].sc.fs, mom[i].sc.sc));
		}
		if(mom[i].fs.sc == 2) {
			rem(mom[i].sc.fs, mom[i].sc.sc);
		}
		if(mom[i].fs.sc == 3) {
			add(mom[i].sc.fs, mom[i].sc.sc);
		}
		t = mom[i].fs.fs;
	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1. * clock() / CLOCKS_PER_SEC * 1000);
		fflush(stderr);
	}
	#endif
	return(0);
}

// by Kim Andrey