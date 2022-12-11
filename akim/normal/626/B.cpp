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

	int cr = 0, cb = 0, cg = 0;
	int n;
	scanf("%d\n", &n);
	string s;
	getline(cin, s);
	for(int i = 0; i < n; i++) {
		cr += s[i] == 'R';
		cg += s[i] == 'G';
		cb += s[i] == 'B';
	}
	bool okR = 0, okG = 0, okB = 0;
	if(cr && cb) okG = 1;
	if(cr && cg) okB = 1;
	if(cg && cb) okR = 1;
	if(cr >= 2 && cb) okB = 1;
	if(cr >= 2 && cg) okG = 1;
	if(cg >= 2 && cr) okR = 1;
	if(cg >= 2 && cb) okB = 1;
	if(cb >= 2 && cr) okR = 1;
	if(cb >= 2 && cg) okG = 1;
	if(cr && !cg && !cb) okR = 1;
	if(!cr && cg && !cb) okG = 1;
	if(!cr && !cg && cb) okB = 1;
	if(okB) printf("B");
	if(okG) printf("G");
	if(okR) printf("R");

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