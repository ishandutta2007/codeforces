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

pair<int, int> ch[maxn], cv[maxn];
int t = 1;

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

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++) {
		int type, p, c;
		scanf("%d%d%d", &type, &p, &c);
		if(type == 1) {
			ch[p] = mp(t++, c);
		} else {
			cv[p] = mp(t++, c);
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(ch[i] > cv[j]) {
				printf("%d ", ch[i].sc);
			} else {
				printf("%d ", cv[j].sc);
			}
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