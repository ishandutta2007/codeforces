#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
#include <unordered_set>
 #include <cfloat>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
 
#define debug(format, ...) printf(format, __VA_ARGS__);

int N; ll X, Y;

int main() {
	scanf("%d%d", &N, &X);
	while(N--) {
		char s[5]; int d; scanf("%s%d", s, &d);
		if(*s == '+') X += d;
		else {
			if(X >= d) X -= d;
			else Y++;
		}
	}

	printf("%lld %lld\n", X, Y);
	return 0;
}