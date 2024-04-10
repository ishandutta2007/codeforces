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
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;*/
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
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;

int n;
int d[1000100][10];
int c[10];
string t;
string all[1000100];
bool del[1000100];
int sz = 0;

bool cmp(string s, string t) {
	return(s + t < t + s);
}

void check(int l) {
//	cout << l << " ";
	int fr = l / 10;
	for(int i = 0; i < 10; i++) d[l][i] = d[fr][i];
	d[l][l % 10]++;
	int lenl = 0;
	for(int i = 0; i < 10; i++) {
		lenl += d[l][i];
		if(d[l][i] > c[i]) return;
	}
	if(n - lenl != l) return;
	bool ok = t[0] != '0';
	for(int i = 0; i < 10; i++) {
		c[i] -= d[l][i];
		if(i && c[i] != 0) ok = 1;
	}
	if(!ok) {
		for(int i = 0; i < 10; i++) {
			c[i] += d[l][i];
		}
		return;
	}

	if(t[0] != '0') all[sz++] = t;
	for(int i = 1; i < 10; i++) {
		string a;
		a.pb(i + '0');
		for(int j = 0; j < min(c[i], 2); j++) {
//		if(c[i])
			all[sz++] = a;
		}
	}
	sort(&all[0], &all[sz], cmp);
	string zeroes;
	for(int i = 0; i < c[0]; i++) {
		zeroes.pb('0');
	}
	if(sz > 1) {
		if(all[0] + zeroes + all[1] > all[1] + zeroes + all[0]) {
			swap(all[0], all[1]);
		}
	}

	bool fir = 0, db[10] = {0};
	for(int i = 0; i < sz; i++) {
		printf("%s", all[i].c_str());
		if(!fir) {
			fir = 1;
			for(int i = 0; i < c[0]; i++) {
				printf("0");
			}
			if(t[0] == '0') printf("%s", t.c_str());
		}
		if(all[i].length() == 1) {
			if(db[all[i][0] - '0'])
			while(c[all[i][0] - '0'] > 2) {
				printf("%s", all[i].c_str());
				c[all[i][0] - '0']--;
			}
			db[all[i][0] - '0'] = 1;
		}
	}

	exit(0);
}

int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
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

	string s;
	getline(cin, s);
	if(s == "01" || s == "10") {
		printf("0");
		return(0);
	}
	n = s.length();
	for(int i = 0; i < n; i++) {
		c[s[i] - '0']++;
	}
	getline(cin, t);
	int m = t.length();;
	for(int i = 0; i < m; i++) {
		c[t[i] - '0']--;
	}

//	string a;
//	a.pb('0');
//	c[0] += t[0] == '0';
//	for(int i = sz - 1 + c[0]; i > c[0]; i--) {
//		swap(all[i], all[i - c[0]]);
//	}
//	for(int i = 1; i <= c[0]; i++) {
//		all[i] = a;
//	}
//	all[c[0]] = t;
//	c[0] -= t[0] == '0';
//	sz += c[0];

	for(int i = 1; i <= 1000000; i++) {
		check(i);
	}

	assert(0);
//	while(1) {}

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