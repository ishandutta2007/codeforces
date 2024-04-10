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

int x[100100];

ll ans = 0, cnt = 0;

void rek(int k, int n) {
	if(k == 0) {
		for(int i = 0; i < n; i++) {
			for(int f = i; f >= 0; f--) {
				if(x[i] < x[f]) {
					ans++;
				}
			}
		}
		cnt++;
		return;
	}
	for(int i = 0; i < n; i++) {
		for(int f = i; f < n; f++) {
			reverse(&x[i], &x[f + 1]);
			rek(k - 1, n);
			reverse(&x[i], &x[f + 1]);
		}
	}
}

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

	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}

	rek(k, n);

	printf("%.9lf", (1. * ans) / (1. * cnt));

	return(0);
}

// by Kim Andrey