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

int a[maxn];

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
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int g = a[0];
	for(int i = 1; i < n; i++) {
		g = __gcd(g, a[i]);
	}

	int nech = 0;
	for(int i = 0; i < n; i++) {
		nech += ((a[i] / g) & 1);
	}
	bool doub = 0;
	if(nech > 1) {
		if(g % 2 == 0) {
			doub = 1;
			g /= 2;
		} else {
			printf("0\n");
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < a[i]; j++) {
					printf("%c", 'a' + i);
				}
			}
			return(0);
		}
	}
	nech = -1;
	for(int i = 0; i < n; i++) {
		if((a[i] / g) & 1) {
			nech = i;
			a[i]--;
		}
	}
	string s;
	for(int i = 0; i < n; i++) {
		int x = a[i] / g;
		while(x) {
			x -= 2;
			s += 'a' + i;
		}
	}

	if(nech != -1) {
		s += 'a' + nech;
		int n = s.length() - 1;
		for(int i = n - 1; i >= 0; i--) {
			s += s[i];
		}
	} else {
		int n = s.length();
		for(int i = n - 1; i >= 0; i--) {
			s += s[i];
		}
	}

	printf("%d\n", g * (doub ? 2 : 1));
	for(int i = 0; i < g; i++) {
		printf("%s", s.c_str());
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