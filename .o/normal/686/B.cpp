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

const int N_ = 105;

int N, A[N_];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j+1 <= N; j++) {
			if(A[j] > A[j+1]) {
				printf("%d %d\n", j, j+1);
				swap(A[j], A[j+1]);
			}
		}
	}

	assert(is_sorted(A+1, A+N+1));
	return 0;
}