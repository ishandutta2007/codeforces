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

long long nd1[] = {+1, +1, -1, -1};
long long nd2[] = {+1, -1, +1, -1};

int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);
	
	long long t; scanf("%I64d", &t);
	for(;t > 0; t--) {
		long long n, k, d1, d2;
		scanf("%I64d%I64d%I64d%I64d", &n, &k, &d1, &d2);
		if(n % 3 != 0) {printf("no\n"); continue;}
		bool ok = 0;
		for(long long i = 0; i < 4; i++) {
			long long s = -d1 * 2 * nd1[i] - d2 * nd2[i] + k;
			if(s % 3 == 0) {
				long long x1 = s / 3, x2 = x1 + d1 * nd1[i], x3 = x2 + d2 * nd2[i];
				if(x1 >= 0 && x2 >= 0 && x3 >= 0) {
					long long z = max(x1, max(x2, x3));
					if(n - k >= z * 3 - x1 - x2 - x3) {ok = 1;}
				}
			}
		}
		if(ok) {printf("yes\n");} else {printf("no\n");}
	}
	
	return(0);
}

// by Kim Andrey