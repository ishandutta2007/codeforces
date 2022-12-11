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

bool b[110][110];

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
	int pos = k - k / 2;
	for(int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		ll bad = mod, posx = -1, posy = -1;
		for(int f = 1; f <= k; f++) {
			ll bd = 0, l = 1;
			for(int g = 1; g <= k; g++) {
				if(b[f][g]) {
					l = g + 1;
					bd = 0;
				} else {
					bd += abs(f - pos) + abs(g - pos);
					if(g - l + 1 > m) {
						bd -= abs(f - pos) + abs(l - pos);
						l++;
					}
					if(g - l + 1 == m && bad > bd) {
						bad = bd, posx = f, posy = l;
					}
				}
			}
		}
		if(bad != mod) {
			cout << posx << " " << posy << " " << posy + m - 1 << "\n";
			for(int i = 0; i < m; i++) {
				b[posx][posy + i] = 1;
			}
		} else {
			cout << "-1\n";
		}
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