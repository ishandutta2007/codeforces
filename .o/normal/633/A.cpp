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
typedef pair<ll, ll> pll;

#define debug(format, ...) printf(format, __VA_ARGS__);
int A, B, C;

int main() {
	scanf("%d%d%d", &A, &B, &C);
	for(int i = 0; i * A <= C; i++) 
		if((C - i * A) % B == 0) return 0 & puts("Yes");
	puts("No");
    return 0;
}