#include <stdio.h>
#include <bits/stdc++.h>
#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name; order_of_key find_by_order

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

int a[maxn][5];

int c[5];

int getval(int a, int c, int n, int k) {
	int ret = 0, b = 0;
	if(a != -1) {
		if(c * 2 > n + k) {
			ret += 500 - a * (500 / 250);
			b = 500;
		} else
		if(c * 4 > n + k) {
			ret += 1000 - a * (1000 / 250);
			b = 1000;
		} else
		if(c * 8 > n + k) {
			ret += 1500 - a * (1500 / 250);
			b = 1500;
		} else
		if(c * 16 > n + k) {
			ret += 2000 - a * (2000 / 250);
			b = 2000;
		} else
		if(c * 32 > n + k) {
			ret += 2500 - a * (2500 / 250);
			b = 2500;
		} else {
			ret += 3000 - a * (3000 / 250);
			b = 3000;
		}
	}
	// cout << ret << " " << b << endl;
	return(ret);
}

int solution() {

	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
			c[j] += (a[i][j] != -1);
		}
	}

	for(int k = 0; k < 1000000; k++) {
		int vasya = getval(a[0][0], c[0], n, k);
		vasya += getval(a[0][1], c[1], n, k);
		vasya += getval(a[0][2], c[2], n, k);
		vasya += getval(a[0][3], c[3], n, k);
		vasya += getval(a[0][4], c[4], n, k);
		int petya = getval(a[1][0], c[0], n, k);
		petya += getval(a[1][1], c[1], n, k);
		petya += getval(a[1][2], c[2], n, k);
		petya += getval(a[1][3], c[3], n, k);
		petya += getval(a[1][4], c[4], n, k);

		// cout << vasya << " " << petya << endl;
		// cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << " " << c[4] << endl;

		if(vasya > petya) {
			printf("%d", k);
			return(0);
		}
		for(int j = 0; j < 5; j++) {
			if(a[0][j] != -1) {
				if(a[1][j] != -1) {
					if(a[0][j] < a[1][j]) {

					} else {
						c[j]++;
					}
				} else {

				}
			} else {
				if(a[1][j] != -1) {
					// c[j]++;
				} else {

				}
			}
		}
	}
	printf("-1");

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(1, 1), mp("", 0)));
}

//by Andrey Kim