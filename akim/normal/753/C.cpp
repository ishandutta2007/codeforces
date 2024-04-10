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

vector<int> vc, tmp, vcc;

bool cmp(int a, int b, int x, int y) {
	map<int, int> ma, mb;
	int xx = 0, yy = 0;
	int aa = a, bb = b;
	xx += aa % 10 == bb % 10;
	if (aa % 10 != bb % 10) {
		ma[aa % 10]++;
		mb[bb % 10]++;
	}
	aa /= 10, bb /= 10;
	xx += aa % 10 == bb % 10;
	if (aa % 10 != bb % 10) {
		ma[aa % 10]++;
		mb[bb % 10]++;
	}
	aa /= 10, bb /= 10;
	xx += aa % 10 == bb % 10;
	if (aa % 10 != bb % 10) {
		ma[aa % 10]++;
		mb[bb % 10]++;
	}
	aa /= 10, bb /= 10;
	xx += aa % 10 == bb % 10;
	if (aa % 10 != bb % 10) {
		ma[aa % 10]++;
		mb[bb % 10]++;
	}
	aa /= 10, bb /= 10;
	for (int i = 0; i < 10; i++) {
		yy += min(ma[i], mb[i]);
	}
	if (xx == x && yy == y) {
		return (1);
	}
	return (0);
}
bool get(int &x, int &y, int a, int b) {
	map<int, int> ma, mb;
	int xx = 0, yy = 0;
	int aa = a, bb = b;
	xx += aa % 10 == bb % 10;
	if (aa % 10 != bb % 10) {
		ma[aa % 10]++;
		mb[bb % 10]++;
	}
	aa /= 10, bb /= 10;
	xx += aa % 10 == bb % 10;
	if (aa % 10 != bb % 10) {
		ma[aa % 10]++;
		mb[bb % 10]++;
	}
	aa /= 10, bb /= 10;
	xx += aa % 10 == bb % 10;
	if (aa % 10 != bb % 10) {
		ma[aa % 10]++;
		mb[bb % 10]++;
	}
	aa /= 10, bb /= 10;
	xx += aa % 10 == bb % 10;
	if (aa % 10 != bb % 10) {
		ma[aa % 10]++;
		mb[bb % 10]++;
	}
	aa /= 10, bb /= 10;
	for (int i = 0; i < 10; i++) {
		yy += min(ma[i], mb[i]);
	}
	x = xx, y = yy;
	return (0);
}

int solution() {

	for (int i = 0; i < 10000; i++) {
		set<int> st;
		int x = i;
		st.insert(x % 10);
		x /= 10;
		st.insert(x % 10);
		x /= 10;
		st.insert(x % 10);
		x /= 10;
		st.insert(x % 10);
		x /= 10;
		if (st.size() == 4) {
			vcc.pb(i);
		}
	}

//	for (int xx = 2345; xx < 10000; xx++) {
//		{
//			set<int> st;
//			int x = xx;
//			st.insert(x % 10);
//			x /= 10;
//			st.insert(x % 10);
//			x /= 10;
//			st.insert(x % 10);
//			x /= 10;
//			st.insert(x % 10);
//			x /= 10;
//			if (st.size() != 4) {
//				continue;
//			}
//		}
//		printf("%04d\n", xx);
		vc.clear();
		tmp.clear();

		vc.insert(vc.begin(), vcc.begin(), vcc.end());

		bool ok = 0;
		for (int i = 0; i < 7; i++) {
		printf("%04d\n", vc[0]);
			fflush(stdout);
			int x, y;
		scanf("%d%d", &x, &y);
//			get(x, y, xx, vc[0]);
			if (x == 4) {
				ok = 1;
				break;
			}
			for (int j = 0; j < (int) vc.size(); j++) {
				if (cmp(vc[0], vc[j], x, y)) {
					tmp.pb(vc[j]);
				}
			}
			vc.clear();
			vc.swap(tmp);
//		random_shuffle(vc.begin(), vc.end());
			int id = 0, cc = 0;
			if (vc.size() < 200)
			for (int j = 0; j < (int) vc.size(); j++) {
				int cnt = 0;
				for (int k = 0; k < vc.size(); k++) {
					int x, y;
					get(x, y, vc[j], vc[k]);
					cnt += x == 3;
				}
				if (cnt > cc) {
					id = j;
				}
			}
			swap(vc[0], vc[id]);
		}
		if (!ok)
			assert(0);
//	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim