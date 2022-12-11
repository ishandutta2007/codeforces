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
const int maxn = 100100;

string s[2], t[2];

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

	getline(cin, s[0]);
	getline(cin, s[1]);

	getline(cin, t[0]);
	getline(cin, t[1]);

	for(int i = 0; i < 10000; i++) {
		if(s[0][0] == 'X') {
			swap(s[0][0], s[0][1]);
		} else
		if(s[0][1] == 'X') {
			swap(s[0][1], s[1][1]);
		} else
		if(s[1][1] == 'X') {
			swap(s[1][1], s[1][0]);
		} else
		if(s[1][0] == 'X') {
			swap(s[1][0], s[0][0]);
		}
		if(s[0] == t[0] && s[1] == t[1]) {
			printf("YES\n");
			return(0);
		}
	}

	printf("NO\n");

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