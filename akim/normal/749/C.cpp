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

string s;
bool ban[maxn];

int solution() {

	int n;
	scanf("%d\n", &n);
	getline(cin, s);
	int bd = 0, br = 0, cd = 0, cr = 0;
	for (int i = 0; i < (int) s.length(); i++) {
		if (s[i] == 'D') {
			cd++;
		}
		if (s[i] == 'R') {
			cr++;
		}
	}
	if (cr == 0) {
		printf("D");
		return (0);
	}
	if (cd == 0) {
		printf("R");
		return (0);
	}
	for (int i = 0; i < (int) s.length(); i++) {
		if (s[i] == 'D') {
			if (bd) {
				bd--;
				cd--;
				if (!cd) {
					printf("R");
					return (0);
				}
				continue;
			}
			br++;
			s.pb('D');
		}
		if (s[i] == 'R') {
			if (br) {
				br--;
				cr--;
				if (!cr) {
					printf("D");
					return (0);
				}
				continue;
			}
			bd++;
			s.pb('R');
		}
	}

	return (0);
}

inline pair<pair<bool, bool>, pair<string, bool> > useinout() {
	return (mp(mp(0, 0), mp("", 0)));
}

//by Andrey Kim