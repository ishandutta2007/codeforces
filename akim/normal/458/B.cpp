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

unsigned long long x[100100], y[100100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	unsigned long long n, m, i;
	scanf("%I64d%I64d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%I64d", &x[i]);
	}
	sort(&x[0], &x[n]);
	for(i = 1; i < n; i++) {x[i] += x[i - 1];}

	for(i = 0; i < m; i++) {
		scanf("%I64d", &y[i]);
	}
	sort(&y[0], &y[m]);

	for(i = 1; i < m; i++) {y[i] += y[i - 1];}

	unsigned long long otv = min(n * y[m - 1], m * x[n - 1]);
	for(i = 0; i < n - 1; i++) {
		otv = min(otv, (n - i - 1) * y[m - 1] + x[i]);
	}
	for(i = 0; i < m - 1; i++) {
		otv = min(otv, (m - i - 1) * x[n - 1] + y[i]);
	}

	printf("%I64d", otv);

	return(0);
}

// by Kim Andrey