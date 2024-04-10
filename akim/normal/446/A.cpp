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

int a[100100], b[100100], c[100100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	

	int n, otv = 0, i, f;
	scanf("%d", &n);
	b[0] = 1; c[n + 1] = 1;
	a[0] = mod; a[n + 1] = -mod;
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(i = 1; i <= n; i++) {
		b[i] = (a[i] > a[i - 1]) ? (b[i - 1] + 1) : 1;
		otv = max(otv, b[i]);
	}
	for(i = n; i >= 1; i--) {
		c[i] = (a[i] < a[i + 1]) ? (c[i + 1] + 1) : 1;
	}
	if(otv != n) {
		otv++;
	}
	for(i = 2; i < n; i++) {
		if(a[i - 1] + 1 < a[i + 1]) {
			otv = max(otv, b[i - 1] + c[i + 1] + 1);
		}
	}	
	
	printf("%d", otv);

	return(0);
}

// by Kim Andrey