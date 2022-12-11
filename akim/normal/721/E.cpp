#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

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

inline pair<pair<bool, bool>, string> useinout();

void init() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(time(0));
	const string file = useinout().sc;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	}
#endif
}

int solve();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
#endif
}

int main() {
	init();
	int exitval = solve();
	finish(exitval);
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

inline pair<pair<bool, bool>, string> useinout() {
	return (mp(mp(0, 0), ""));
}

pair<int, int> p[maxn];
set<pair<int, int> > st;

int solve() {

	int n, pp, t;
	scanf("%*d%d%d%d", &n, &pp, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &p[i].fs, &p[i].sc);
	}

	int mx = 0, i = 0;
	priority_queue<pair<int, int> > q;
	q.push(mp(0, 0));
	while (!q.empty()) {
		int pos = -q.top().fs, cnt = q.top().sc;
		q.pop();
		if (cnt < mx || st.count(mp(pos, cnt)))
			continue;
		mx = cnt;
		st.insert(mp(pos, cnt));
		while (i < n && p[i].sc < pos) {
			i++;
		}
		if (i == n)
			continue;
		if (pos < p[i].fs) {
			pos = p[i].fs;
		}

		q.push(mp(-max((p[i].sc - pos) / pp * pp + pos + t, i + 1 != n ? p[i + 1].fs : mod), cnt + (p[i].sc - pos) / pp));
		if (i + 1 != n) {
			q.push(mp(-(p[i + 1].fs), cnt));
		}
	}

	printf("%d\n", mx);

	return (0);
}

// by Andrey Kim