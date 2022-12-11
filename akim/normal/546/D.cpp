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
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 5000100;

int rw[maxn];

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

	for(int i = 2; i < maxn; i++) {
		if(rw[i] == 0) {
			rw[i] = 1;
			for(int f = i * 2; f < maxn; f += i) {
				rw[f] = i;
			}
		} else {
			rw[i] = rw[i / rw[i]] + 1;
		}
	}
	for(int i = 1; i < maxn; i++) {
		rw[i] += rw[i - 1];
	}

	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", rw[a] - rw[b]);
	}

	return(0);
}

// by Kim Andrey