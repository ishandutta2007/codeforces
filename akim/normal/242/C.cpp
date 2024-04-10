#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

set<pair<int, int> > st;
vector<pair<pair<int, int>, int > > vc;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	int x0, y0, x1, y1, k; scanf("%d%d%d%d%d", &x0, &y0, &x1, &y1, &k);
	for(; k > 0; k--) {
		int r, a, b;
		scanf("%d%d%d", &r, &a, &b);
		for(; a <= b; a++) {
			st.insert(mp(r, a));
		}
	}
	st.erase(mp(x0, y0));
	vc.pb(mp(mp(x0, y0), 0));
	int i = 0;
	while(i < vc.size()) {
		int x = vc[i].fs.fs, y = vc[i].fs.sc, z = vc[i].sc; i++;

		if(x == x1 && y == y1) {
			printf("%d", z);
			return(0);
		}

		if(st.count(mp(x + 1, y))) {
			st.erase(mp(x + 1, y));
			vc.pb(mp(mp(x + 1, y), z + 1));
		}
		if(st.count(mp(x - 1, y))) {
			st.erase(mp(x - 1, y));
			vc.pb(mp(mp(x - 1, y), z + 1));
		}
		if(st.count(mp(x, y + 1))) {
			st.erase(mp(x, y + 1));
			vc.pb(mp(mp(x, y + 1), z + 1));
		}
		if(st.count(mp(x, y - 1))) {
			st.erase(mp(x, y - 1));
			vc.pb(mp(mp(x, y - 1), z + 1));
		}
		if(st.count(mp(x + 1, y + 1))) {
			st.erase(mp(x + 1, y + 1));
			vc.pb(mp(mp(x + 1, y + 1), z + 1));
		}
		if(st.count(mp(x + 1, y - 1))) {
			st.erase(mp(x + 1, y - 1));
			vc.pb(mp(mp(x + 1, y - 1), z + 1));
		}
		if(st.count(mp(x - 1, y + 1))) {
			st.erase(mp(x - 1, y + 1));
			vc.pb(mp(mp(x - 1, y + 1), z + 1));
		}
		if(st.count(mp(x - 1, y - 1))) {
			st.erase(mp(x - 1, y - 1));
			vc.pb(mp(mp(x - 1, y - 1), z + 1));
		}
	}
	printf("-1");

	return(0);
}

// by Kim Andrey