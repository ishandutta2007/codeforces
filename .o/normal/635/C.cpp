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
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

ll S, X;
int main() {
	scanf("%lld%lld", &S, &X);

	try {
		if(S < X) throw 0ll;
		if((S - X) % 2) throw 0ll;
		if(X & ((S - X) >> 1)) throw 0ll;

		ll ret = 1;
		for(ll t = X; t > 0; t >>= 1) if(t & 1) ret <<= 1;
		if(S == X) ret -= 2;
		throw ret;
	}catch(ll x) {
		printf("%lld\n", x);
	}
    return 0;
}