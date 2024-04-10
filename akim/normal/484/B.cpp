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
const double pi = acos(-1.0);

int x[200200], n, otv;

void binfind(int z, int y) {
	int l = 0, r = n;
	while(l + 1 < r) {
		int m = (l + r) >> 1;
		if(x[m] <= z) {
			l = m;
		} else {
			r = m;
		}
	}
	otv = max(otv, x[l] % y);
	l--;
	if(l >= 0 && x[l] >= y) {
		otv = max(otv, x[l] % y);
	}
}

int main() {

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	sort(&x[0], &x[n]);
	n = (int)(unique(x, x + n) - x);
	otv = 0;
	for(int i = n - 1; i >= 0; i--) {
		int z = x[i];
		while(z - x[i] <= 1100000) {
			binfind(z, x[i]);
			z += x[i];
		}
	}
	cout << otv;
	return(0);
}

// by Kim Andrey