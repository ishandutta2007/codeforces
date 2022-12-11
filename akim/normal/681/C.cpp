//#include <stdio.h>
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

inline void gettime() {
	fprintf(stderr, "\ntime: %.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout();

void init() {
#ifdef SOL
	if (useinout().fs.fs)
		freopen("input.txt", "r", stdin);
	if (useinout().fs.sc)
		freopen("output.txt", "w", stdout);
#else
	srand(time(0));
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

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

bool comp(int x, int y) {
	return x > y;
}
typedef vector<int> vi;
typedef vector<string> vs;

int solve() {

	int n;
	scanf("%d", &n);
	vs sol;
	priority_queue<int, vi, function<bool(int, int)> > q(comp);
	for (int nn = 0; nn < n; nn++) {
		char s[100];
		scanf("%s", s);
		if (s[0] == 'i') {
			int x;
			scanf("%d", &x);
			q.push(x);
			sol.push_back("insert " + to_string(x));
		} else if (s[0] == 'g') {
			int x;
			scanf("%d", &x);
			if (q.empty()) {
				sol.push_back("insert " + to_string(x));
				sol.push_back("getMin " + to_string(x));
				q.push(x);
				continue;
			}
			int y = q.top();
			if (y > x) {
				sol.push_back("insert " + to_string(x));
				sol.push_back("getMin " + to_string(x));
				q.push(x);
			} else if (y < x) {
				while (true) {
					sol.push_back("removeMin");
					y = q.top();
					q.pop();
					if (q.empty()) {
						sol.push_back("insert " + to_string(x));
						sol.push_back("getMin " + to_string(x));
						q.push(x);
						break;
					}
					y = q.top();
					if (y > x) {
						sol.push_back("insert " + to_string(x));
						sol.push_back("getMin " + to_string(x));
						q.push(x);
						break;
					} else if (y == x) {
						sol.push_back("getMin " + to_string(x));
						break;
					}
				}
			} else {
				sol.push_back("getMin " + to_string(x));
			}
		} else {
			if (q.empty()) {
				sol.push_back("insert 1");
				sol.push_back("removeMin");
			} else {
				int y = q.top();
				q.pop();
				sol.push_back("removeMin");
			}
		}
	}
	printf("%d\n", sol.size());
	for (int i = 0; i < sol.size(); i++) {
		printf("%s\n", sol[i].c_str());
	}

	return (0);
}

// by Andrey Kim