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

long long x[500100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);

	long long n, s = 0;
	scanf("%I64d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%I64d", &x[i]);
		s += x[i];
	}
	if(s % 3 != 0) {printf("0"); return(0);}
	s /= 3;
	long long c1 = 0, otv = 0;
	for(int i = 0; i < n - 1; i++) {
		x[i] += (i - 1 >= 0) ? x[i - 1] : 0;
		if(x[i] == s * 2) {otv += c1;}
		if(x[i] == s) {c1++;}
	}

	printf("%I64d", otv);

	return(0);
}

// by Kim Andrey