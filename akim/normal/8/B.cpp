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

set<pair<int, int> > st;

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

	string s;
	getline(cin, s);
	int n = s.length();
	int x = 0, y = 0, px = -1, py = -1;
	bool bad = 0;
	for(int i = 0; i < n; i++) {

		if(st.count(mp(x, y))) {
			bad = 1;
		} else {
			st.insert(mp(x, y));
		}
		if(x - 1 != px || y != py) {
			if(st.count(mp(x - 1, y))) {
				bad = 1;
			}
		}
		if(x + 1 != px || y != py) {
			if(st.count(mp(x + 1, y))) {
				bad = 1;
			}
		}
		if(x != px || y - 1 != py) {
			if(st.count(mp(x, y - 1))) {
				bad = 1;
			}
		}
		if(x != px || y + 1 != py) {
			if(st.count(mp(x, y + 1))) {
				bad = 1;
			}
		}

		px = x, py = y;
		x += s[i] == 'L' ? -1 : s[i] == 'R' ? 1 : 0;
		y += s[i] == 'D' ? -1 : s[i] == 'U' ? 1 : 0;
	}
	if(st.count(mp(x, y))) {
		bad = 1;
	} else {
		st.insert(mp(x, y));
	}
	if(x - 1 != px || y != py) {
		if(st.count(mp(x - 1, y))) {
			bad = 1;
		}
	}
	if(x + 1 != px || y != py) {
		if(st.count(mp(x + 1, y))) {
			bad = 1;
		}
	}
	if(x != px || y - 1 != py) {
		if(st.count(mp(x, y - 1))) {
			bad = 1;
		}
	}
	if(x != px || y + 1 != py) {
		if(st.count(mp(x, y + 1))) {
			bad = 1;
		}
	}

	if(bad) {
		printf("BUG");
	} else {
		printf("OK");
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