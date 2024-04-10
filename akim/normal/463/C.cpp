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

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.0);

long long x[5000], y[5000], z[2100][2100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < n; f++) {
			long long c; scanf("%I64d", &c);
			z[i][f] = c;
			x[n + f - i] += c;
			y[i + f] += c;
		}
	}
	int x1 = 0, x2 = 0, y1 = 1, y2 = 0;
	long long c1 = 0, c2 = 0;
	for(int i = 0; i < n; i++) {
		for(int f = 0; f < n; f++) {
			long long zn = x[n + f - i] + y[i + f] - z[i][f];
			if((i + f) % 2 == 0 && c2 < zn) {
				c2 = zn;
				x2 = i; y2 = f;
			}
			if((i + f) % 2 == 1 && c1 < zn) {
				c1 = zn;
				x1 = i; y1 = f;
			}
		}
	}
	printf("%I64d\n", c1 + c2);
	printf("%d %d %d %d", x2 + 1, y2 + 1, x1 + 1, y1 + 1);
	
	return(0);
}

// by Kim Andrey