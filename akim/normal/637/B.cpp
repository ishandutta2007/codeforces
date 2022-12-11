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
const int maxn = 2000100;

string s[maxn];
map<char, int> bor[maxn];
bool ed[maxn];
int sz = 1;

bool add(string &s) {
	int cur = 0;
	for(int i = 0; i < (int)s.length(); i++) {
		if(!bor[cur].count(s[i])) {
			bor[cur][s[i]] = sz++;
		}
		cur = bor[cur][s[i]];
	}
	if(ed[cur]) {
		return(0);
	} else {
		ed[cur] = 1;
		return(1);
	}
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
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int n;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++) {
		getline(cin, s[i]);
	}
	for(int i = n - 1; i >= 0; i--) {
		if(add(s[i])) {
			printf("%s\n", s[i].c_str());
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