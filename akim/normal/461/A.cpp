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

long long x[300300], otv = 0;

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%I64d", &x[i]);
	}
	sort(&x[1], &x[n + 1]);
	long long i;
	for(i = 1; i < n; i++) {
		otv += (i + 1) * x[i];
	}
	otv += i * x[i];
	printf("%I64d", otv);
	
	return(0);
}

// by Kim Andrey