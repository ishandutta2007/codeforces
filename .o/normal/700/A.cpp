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

int N;lf L, V1, V2; int K;
int main() {
    scanf("%d%lf%lf%lf%d", &N, &L, &V1, &V2, &K);

    int m = N / K + !!(N % K) - 1;
    lf r = 2 * V1 * V2 / (V1 + V2);
    lf c = r * m + V2;
    lf best = L / c;
    lf ans = best + (L - best * V2) / V1;

    printf("%.10f\n", ans);
	return 0;
}