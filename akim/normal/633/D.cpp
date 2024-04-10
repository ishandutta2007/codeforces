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

int a[maxn];
map<int, int> ma1, ma2;
set<pair<int, int> > chkd;

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
		scanf("%d", &a[i]);
		ma1[a[i]]++;
	}
	int ans = max(2, ma1[0]);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++, j += (j == i)) {
			int len = 1;
			int lf = a[i], rg = a[j];

			if((lf == 0 && rg == 0) || chkd.count(mp(lf, rg))) continue;
               chkd.insert(mp(lf, rg));
			ma2.clear();
			ma2[lf]++, ma2[rg]++;
			if(ma2[rg - lf] + 1 <= ma1[rg - lf]) continue;

			while(ma2[rg] <= ma1[rg]) {
				len++;
				int nw = lf + rg;
				lf = rg, rg = nw;
				ma2[rg]++;
			}
			ans = max(ans, len);
		}
	}

	printf("%d", ans);

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