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

	int n, m, a = 0, b = 1;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		if(t == 2) {
			swap(a, b);
		} else {
			int c;
			scanf("%d", &c);
			c = -c;
			if(c & 1) {
				if(c > 0) {
					int na = (b + c - 1 + 3 * n) % n;
					int nb = (a + c + 1 + 3 * n) % n;
					a = na, b = nb;
				} else {
					int na = (b + c - 1 + 3 * n) % n;
					int nb = (a + c + 1 + 3 * n) % n;
					a = na, b = nb;
				}
			} else {
				int na = (a + c + 2 * n) % n;
				int nb = (b + c + 2 * n) % n;
				a = na, b = nb;
			}
		}
//		cout << a << " " << b << endl;
	}
	for(int i = 0; i * 2 < n; i++) {
		printf("%d %d ", (a + i * 2) % n + 1, (b + i * 2) % n + 1);
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