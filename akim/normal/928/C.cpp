#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T1, typename T2> using ordered_map = tree<T1, T2, std::less<T1>, rb_tree_tag, tree_order_statistics_node_update>;

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

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

#ifdef SOL
double starttime;
#endif

void initialization() {
#ifdef SOL
	starttime = 1000. * clock() / CLOCKS_PER_SEC;
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(__rdtsc());
	const string file = useinout().sc.fs;
	if (!file.empty()) {
		freopen((file + ".in").c_str(), "r", stdin);
		freopen((file + ".out").c_str(), "w", stdout);
	} else
	if(useinout().sc.sc) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
#endif
}

int solution();

void finish(int exitval) {
	fflush(stdout);
#ifdef SOL
	fprintf(stderr, "\n-----------------\nexit value: %d\ntime: %.3lf ms\n-----------------\n", exitval, 1000. * clock() / CLOCKS_PER_SEC - starttime);
#endif
}

int main() {
	initialization();
	finish(solution());
	return (0);
}

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

char buff[maxn];
map<string, int> used;
map<pair<string, int>, map<pair<string, int>, bool> > rb;

int solution() {

	int n;
	scanf("%d", &n);
	string sp;
	int vp;
	for(int i = 0; i < n; i++) {
		int v;
		scanf("%s %d", buff, &v);
		string s(buff);
		if(!i) sp = s, vp = v;

		rb[mp(s, v)] = map<pair<string, int>, bool>();
		int m;
		scanf("%d", &m);
		for(int j = 0; j < m; j++) {
			int u;
			scanf("%s %d", buff, &u);
			string t(buff);
			rb[mp(s, v)][mp(t, u)] = 1;
		}
	}
	priority_queue<pair<int, pair<int, string> > > q;
	q.push(mp(0, mp(vp, sp)));
	while(!q.empty()) {
		int d = -q.top().fs;
		string name = q.top().sc.sc;
		int version = q.top().sc.fs;
		q.pop();
		if(used.count(name)) continue;
		used[name] = version;
		for(pair<pair<string, int>, bool> w : rb[mp(name, version)]) {
			pair<string, int> p = w.fs;
			q.push(mp(-(d + 1), mp(p.sc, p.fs)));
		}
	}

	used.erase(sp);
	printf("%d\n", used.size());
	for(pair<string, int> p : used) {
		printf("%s %d\n", p.fs.c_str(), p.sc);
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 0), mp("", 0)));
}

//by Andrey Kim