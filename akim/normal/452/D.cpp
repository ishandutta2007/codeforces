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

long long x[10100];

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	long long k, n1, n2, n3, t1, t2, t3;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &k, &n1, &n2, &n3, &t1, &t2, &t3);
	for(long long i = 0; i < k; i++) {
		long long t = 0;
		if(i - n1 >= 0) {
			t = max(t, x[i - n1] + t1);
		}
		if(i - n2 >= 0) {
			t = max(t + t1, x[i - n2] + t1 + t2) - t1;
		}
		if(i - n3 >= 0) {
			t = max(t + t1 + t2, x[i - n3] + t1 + t2 + t3) - t1 - t2;
		}
		x[i] = t;
	}

	printf("%I64d", x[k - 1] + t1 + t2 + t3);
	
	return(0);
}

// by Kim Andrey