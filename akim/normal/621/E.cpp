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

int matrix[150][150];
int res[150][150];
int cur[150][150];

void binpow(int a, int x) {
	for(int i = 0; i < x; i++) {
		for(int j = 0; j < x; j++) {
			res[i][j] = 0;
		}
		res[i][i] = 1;
	}
	while(a) {
		if(a & 1) {
			for(int i = 0; i < x; i++) {
				for(int j = 0; j < x; j++) {
					cur[i][j] = 0;
					for(int k = 0; k < x; k++) {
						cur[i][j] = (cur[i][j] + res[i][k] * 1ll * matrix[k][j]) % mod;
					}
				}
			}
			for(int i = 0; i < x; i++) {
				for(int j = 0; j < x; j++) {
					res[i][j] = cur[i][j];
				}
			}
		}

		for(int i = 0; i < x; i++) {
			for(int j = 0; j < x; j++) {
				cur[i][j] = 0;
				for(int k = 0; k < x; k++) {
					cur[i][j] = (cur[i][j] + matrix[i][k] * 1ll * matrix[k][j]) % mod;
				}
			}
		}
		for(int i = 0; i < x; i++) {
			for(int j = 0; j < x; j++) {
				matrix[i][j] = cur[i][j];
			}
		}

		a >>= 1;
	}
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

	int n, b, k, x;
	scanf("%d%d%d%d", &n, &b, &k, &x);
	for(int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		for(int j = 0; j < x; j++) {
			matrix[j][(j * 10 + a) % x]++;
		}
	}

	binpow(b, x);

	printf("%d", res[0][k]);

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