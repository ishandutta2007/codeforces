#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//																														tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

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

void initialization() {
#ifdef SOL
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
	}
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
	fprintf(stderr, "\nexit value: %d\ntime: %.3lf ms\n", exitval, 1000. * clock() / CLOCKS_PER_SEC);
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

vector<int> rb[256];
vector<int> vc;
bool w[256];

bool ask(int n) {
	if (w[n])
		return (0);
	w[n] = 1;
	printf("? %d\n", n);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	for (int i = 0; i < x; i++) {
		int y;
		scanf("%d", &y);
		rb[n].pb(y);
	}
	if (x == 2) {
		printf("! %d\n", n);
		fflush(stdout);
		return (1);
	}
	return (0);
}

void sol(int n) {
	vc.clear();
	for (int i = 0; i < 256; i++) {
		rb[i].clear();
		w[i] = 0;
	}
	int v = 1, d = n - 1;
	if (ask(v))
		return;
	if (rb[v].size() != 1) {
		vc.pb(v);
		{
			int u = v;
			while (rb[u].size() != 1) {
				int x;
				for (int i = 0; i < (int) rb[u].size(); i++) {
					if (!w[rb[u][i]]) {
						x = rb[u][i];
						break;
					}
				}
				u = x;
				vc.pb(u);
				if (ask(u))
					return;
			}
		}
		reverse(vc.begin(), vc.end());
		{
			int u = v;
			while (rb[u].size() != 1) {
				int x;
				for (int i = 0; i < (int) rb[u].size(); i++) {
					if (!w[rb[u][i]]) {
						x = rb[u][i];
						break;
					}
				}
				u = x;
				vc.pb(u);
				if (ask(u))
					return;
			}
		}
		v = vc[vc.size() / 2];
		d = n - vc.size() / 2 - 1;
	}

	int u;
	for (int i = 0; i < (int) rb[v].size(); i++) {
		if (!w[rb[v][i]]) {
			u = rb[v][i];
		}
	}
	d--;

	while (d > 2) {
		vc.resize(n - d - 1);
//		cout << "here" << " " << d << endl;
		vc.pb(u);
		if (ask(u))
			return;
		int vv = u;
		{
			int u = vv;
			while (rb[u].size() != 1) {
				int x;
				for (int i = 0; i < (int) rb[u].size(); i++) {
					if (!w[rb[u][i]]) {
						x = rb[u][i];
						break;
					}
				}
				u = x;
				vc.pb(u);
				if (ask(u))
					return;
			}
		}
//		cout << vc.size() << endl;
		v = vc[vc.size() / 2];
		d = n - vc.size() / 2 - 1;
		for (int i = 0; i < (int) rb[v].size(); i++) {
			if (!w[rb[v][i]]) {
				u = rb[v][i];
			}
		}
		d--;
	}

//	cout << "bfs" << " " << d << endl;
	if (d <= 2) {
		vector<pair<int, int> > bfs;
		bfs.pb(mp(u, d));
		while (bfs.size() > 1 || (bfs.size() == 1 && bfs.back().sc != 0)) {
			int v = bfs.back().fs, d = bfs.back().sc;
			bfs.ppb();
			if (ask(v))
				return;
			if (d == 0) {
				continue;
			}
			for (int i = 0; i < (int) rb[v].size(); i++) {
				if (!w[rb[v][i]]) {
					bfs.pb(mp(rb[v][i], d - 1));
				}
			}
		}
		printf("! %d\n", bfs.back().fs);
		fflush(stdout);
		return;
	}

}

int solution() {

	int t;
	scanf("%d", &t);
	for (; t--;) {
		int n;
		scanf("%d", &n);
		sol(n);
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim