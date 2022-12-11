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

string s[maxn];
int sz = 0;

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

	int len = 0;
	while(getline(cin, s[sz])) {
		len = max(len, (int)s[sz++].length());
	}

	bool tol = 0;

	for(int i = 0; i < len + 2; i++) {
		cout << "*";
	}cout << endl;

	for(int i = 0; i < sz; i++) {
		cout << "*";
		int ots = (len - s[i].length()) / 2;
		int rots = (len - s[i].length()) - ots;
		if(ots != rots) {
			if(tol) swap(ots, rots);
			tol = !tol;
		}
		for(int i = 0; i < ots; i++) {
			cout << " ";
		}
		cout << s[i];
		for(int i = 0; i < rots; i++) {
			cout << " ";
		}
		cout << "*\n";
	}

	for(int i = 0; i < len + 2; i++) {
		cout << "*";
	}cout << endl;

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