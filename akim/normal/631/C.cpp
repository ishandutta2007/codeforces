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

int a[maxn], b[maxn];
multiset<int> st;
set<pair<int, pair<int, int> > > stzp;
set<pair<int, pair<int, int> > >::iterator it;

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
		scanf("%d", &a[i]);
		st.insert(a[i]);
	}

	stzp.insert(mp(0, mp(mod, 0)));
	for(int i = 0; i < m; i++) {
		int tp, rg;
		scanf("%d%d", &tp, &rg);
		stzp.insert(mp(rg, mp(i, tp)));
	}
	int nm = -1, rg = n, type = 0;
	while(!stzp.empty()) {
		it = stzp.end(), it--;
		if(it -> sc.fs < nm) {
			stzp.erase(it);
			continue;
		}
		while(rg > (it -> fs)) {
			rg--;
			if(type == 0) {
				b[rg] = a[rg];
				st.erase(st.find(a[rg]));
			} else
			if(type == 1) {
				int val = *st.rbegin();
				b[rg] = val;
				st.erase(st.find(val));
			} else {
				int val = *st.begin();
				b[rg] = val;
				st.erase(st.find(val));
			}
		}
		nm = it -> sc.fs;
		type = it -> sc.sc;
		stzp.erase(it);
	}

	for(int i = 0; i < n; i ++) {
		printf("%d ", b[i]);
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