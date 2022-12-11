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

	char c[3][3];
	int x = 0, o = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> c[i][j];
			if(c[i][j] == 'X') x++;
			if(c[i][j] == '0') o++;
		}
	}

	if(x < o || x - o > 1) {
		printf("illegal");
		return(0);
	}
	bool xwon = 0, owon = 0;
	xwon |= c[0][0] == 'X' && c[0][1] == 'X' && c[0][2] == 'X';
	xwon |= c[1][0] == 'X' && c[1][1] == 'X' && c[1][2] == 'X';
	xwon |= c[2][0] == 'X' && c[2][1] == 'X' && c[2][2] == 'X';
	xwon |= c[0][0] == 'X' && c[1][0] == 'X' && c[2][0] == 'X';
	xwon |= c[0][1] == 'X' && c[1][1] == 'X' && c[2][1] == 'X';
	xwon |= c[0][2] == 'X' && c[1][2] == 'X' && c[2][2] == 'X';
	xwon |= c[0][0] == 'X' && c[1][1] == 'X' && c[2][2] == 'X';
	xwon |= c[2][0] == 'X' && c[1][1] == 'X' && c[0][2] == 'X';

	owon |= c[0][0] == '0' && c[0][1] == '0' && c[0][2] == '0';
	owon |= c[1][0] == '0' && c[1][1] == '0' && c[1][2] == '0';
	owon |= c[2][0] == '0' && c[2][1] == '0' && c[2][2] == '0';
	owon |= c[0][0] == '0' && c[1][0] == '0' && c[2][0] == '0';
	owon |= c[0][1] == '0' && c[1][1] == '0' && c[2][1] == '0';
	owon |= c[0][2] == '0' && c[1][2] == '0' && c[2][2] == '0';
	owon |= c[0][0] == '0' && c[1][1] == '0' && c[2][2] == '0';
	owon |= c[2][0] == '0' && c[1][1] == '0' && c[0][2] == '0';

	if(xwon && owon) {
		printf("illegal");
		return(0);
	}

	if(xwon && x == o) {
		printf("illegal");
		return(0);
	}

	if(owon && x - 1 == o) {
		printf("illegal");
		return(0);
	}

	if(xwon) {
		printf("the first player won");
		return(0);
	}
	if(owon) {
		printf("the second player won");
		return(0);
	}

	if(x == 5 && o == 4) {
		printf("draw");
		return(0);
	}

	if(x - 1 == o) {
		printf("second");
		return(0);
	}

	if(x == o) {
		printf("first");
		return(0);
	}
	assert(0);
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