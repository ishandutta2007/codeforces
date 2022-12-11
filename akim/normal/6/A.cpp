#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);



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

	int a[4];
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
	bool log1 = 0, log2 = 0;
	for(int i = 0; i < 4; i++) {
		for(int f = 0; f < 4; f++) {
			for(int g = 0; g < 4; g++) {
				if(i != f && i != g && f != g) {
					if(a[i] < a[f] + a[g] && a[f] < a[i] + a[g] && a[g] < a[f] + a[i]) {
						log1 = 1;
					}
					if(a[i] == a[f] + a[g]) {
						log2 = 1;
					}
				}
			}
		}
	}

	if(log1) {
		cout << "TRIANGLE";
	} else {
		if(log2) {
			cout << "SEGMENT";
		} else {
			cout << "IMPOSSIBLE";
		}
	}

	return(0);
}

// by Kim Andrey