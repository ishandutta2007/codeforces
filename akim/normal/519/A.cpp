#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <stdio.h>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

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
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int white = 0, black = 0;
	for(int i = 0; i < 8; i++) {
		for(int f = 0; f < 8; f++) {
			char c;
			cin >> c;
			if(c == 'q') black += 9;
			if(c == 'r') black += 5;
			if(c == 'b') black += 3;
			if(c == 'n') black += 3;
			if(c == 'p') black += 1;
			if(c == 'Q') white += 9;
			if(c == 'R') white += 5;
			if(c == 'B') white += 3;
			if(c == 'N') white += 3;
			if(c == 'P') white += 1;
		}
	}

	if(white == black) {
		cout << "Draw\n";
	} else
	if(white > black) {
		cout << "White\n";
	} else
	if(white < black) {
		cout << "Black\n";
	}

	return(0);
}

// by Kim Andrey