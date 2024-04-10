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

const double eps = 1e-9;
const int mod = (int) 1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int x11, x12, y11, y12;
int x21, x22, y21, y22;

int check(int x1, int x2, int y1, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return (ret);
}

int ins(int x1, int x2, int y1, int y2) {
	return (x1 <= x21 && x2 >= x22 && y1 <= y21 && y2 >= y22);
}

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
		if (!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
#endif

	int n;
	scanf("%d", &n);
	x11 = 1, x12 = n, y11 = 1, y12 = n;
	{
		int l = x11, r = x12 + 1;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(m, x12, y11, y12) >= 1) {
				l = m;
			} else {
				r = m;
			}
		}
		x11 = l;
	}
	{
		int l = x11 - 1, r = x12;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(x11, m, y11, y12) >= 1) {
				r = m;
			} else {
				l = m;
			}
		}
		x12 = r;
	}
	{
		int l = y11, r = y12 + 1;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(x11, x12, m, y12) >= 1) {
				l = m;
			} else {
				r = m;
			}
		}
		y11 = l;
	}
	{
		int l = y11 - 1, r = y12;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(x11, x12, y11, m) >= 1) {
				r = m;
			} else {
				l = m;
			}
		}
		y12 = r;
	}

	x21 = 1, x22 = n, y21 = 1, y22 = n;
	swap(x11, x21);
	swap(x12, x22);
	swap(y11, y21);
	swap(y12, y22);

	{
		int l = x11, r = x12 + 1;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(m, x12, y11, y12) - ins(m, x12, y11, y12) >= 1) {
				l = m;
			} else {
				r = m;
			}
		}
		x11 = l;
	}
	{
		int l = x11 - 1, r = x12;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(x11, m, y11, y12) - ins(x11, m, y11, y12) >= 1) {
				r = m;
			} else {
				l = m;
			}
		}
		x12 = r;
	}
	{
		int l = y11, r = y12 + 1;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(x11, x12, m, y12) - ins(x11, x12, m, y12) >= 1) {
				l = m;
			} else {
				r = m;
			}
		}
		y11 = l;
	}
	{
		int l = y11 - 1, r = y12;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (check(x11, x12, y11, m) - ins(x11, x12, y11, m) >= 1) {
				r = m;
			} else {
				l = m;
			}
		}
		y12 = r;
	}

	printf("! %d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22, y22);
	fflush(stdout);

#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
#endif
	return (0);
}

// by Andrey Kim