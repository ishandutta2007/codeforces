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
const int maxn = 200100;

int pr[maxn], a[maxn] = {-1};

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

	int n, m, s, d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	n++;
	for(int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(&a[0], &a[n]);

	int l = 0, r = 1;
	while(l < r) {
		if(l + 1 < n && a[l + 1] - a[l] - 2 >= s) {
			while(r < n && a[l + 1] - 1 + d > a[r]) {
				pr[r] = l;
				r++;
			}
		}
		l++;
	}

	if(r < n) {
		printf("IMPOSSIBLE\n");
		return(0);
	}

	vector<pair<string, int> > ans;
	r--;
	int cur = m;
	while(cur > 0) {
		if(cur == a[r] + 1) {
			ans.pb(mp("JUMP", a[r] + 1 - a[pr[r] + 1] + 1));
			cur = a[pr[r] + 1] - 1;
			while(a[r] >= cur) r--;
		} else {
			ans.pb(mp("RUN", cur - a[r] - 1));
			cur = a[r] + 1;
		}
	}
	for(int i = (int)ans.size() - 1; i >= 0; i--) {
		printf("%s %d\n", ans[i].fs.c_str(), ans[i].sc);
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