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
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N_ = 100500;
const int M_ = 100500;

int N, K, A, B, C, D;

int main() {
	scanf("%d%d%d%d%d%d", &N, &K, &A, &B, &C, &D);
	if(N == 4 || K <= N) return 0 & puts("-1");

	printf("%d %d ", A, C);
	for(int i = 1; i <= N; i++) {
		if(i != A && i != B && i != C && i != D) 
			printf("%d ", i);
	}
	printf("%d %d\n", D, B);

	printf("%d %d ", C, A);
	for(int i = 1; i <= N; i++) {
		if(i != A && i != B && i != C && i != D) 
			printf("%d ", i);
	}
	printf("%d %d\n", B, D);

    return 0;
}