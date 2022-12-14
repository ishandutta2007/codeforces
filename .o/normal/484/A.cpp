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

int N;
int main() {
	scanf("%d", &N);
	while(N--) {
		ll l, r; scanf("%lld%lld", &l, &r);
		ll ans = 0;
		for(int b = 63; b >= 0; b--) {
			if(((l >> b) & 1) ^ ((r >> b) & 1)) {
				l ^= ans;
				r ^= ans;
				if(r == (2ll << b) - 1) ans |= r;
				else for(; --b >= 0; ) ans |= 1ll << b;
				break;
			}
			ans |= l & (1ll << b);
		}

		printf("%lld\n", ans);

	}
    return 0;
}