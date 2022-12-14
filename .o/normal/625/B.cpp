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

const int N_ = 1050;

char A[100500], P[35];

int AN, PN; 
int main() {
	scanf("%s%s", A, P);
	AN = strlen(A);
	PN = strlen(P);

	int ans = 0;
	for(int i = 0; i + PN - 1 < AN; i++) {
		if(!strncmp(A+i, P, PN)) {
			A[i + PN - 1] = '#';
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}