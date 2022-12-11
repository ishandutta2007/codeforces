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



int main() {

//	freopen("*.in","r",stdin);
//	freopen("*.out","w",stdout);


	long long n, a, b; scanf("%I64d%I64d%I64d", &n, &a, &b); n *= 6; n = max(a * b, n);
	while(1) {
		long long sq = sqrt(n);
		for(long long i = a; i <= sq; i++) {
			if(n % i == 0 && n / i >= b) {
				printf("%I64d\n%I64d %I64d", n, i, n / i);
				return(0);
			}
		}
		for(long long i = b; i <= sq; i++) {
			if(n % i == 0 && n / i >= a) {
				printf("%I64d\n%I64d %I64d", n, n / i, i);
				return(0);
			}
		}
		n++;
	}

	return(0);
}

// by Kim Andrey