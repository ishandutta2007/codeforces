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

set<pair<ll, pair<ll, ll> > > st;
ll sz = 0, lst = 0;

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

	ll n, b;
	scanf("%lld%lld", &n, &b); b++;
	for(int i = 0; i < n; i++) {
		ll t, d;
		scanf("%lld%lld", &t, &d);
		st.insert(mp(t, mp(1, d)));
	}
	while(!st.empty()) {
		pair<ll, pair<ll, ll> > p = *st.begin();
		st.erase(st.begin());
		if(p.sc.fs == -1) {
			sz--;
		} else
		if(sz == 0) {
			lst = p.fs + p.sc.sc;
			printf("%lld ", lst);
			st.insert(mp(lst, mp(-1, 0)));
			sz++;
		} else
		if(sz == b) {
			printf("-1 ");
		} else {
			lst += p.sc.sc;
			printf("%lld ", lst);
			st.insert(mp(lst, mp(-1, 0)));
			sz++;
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