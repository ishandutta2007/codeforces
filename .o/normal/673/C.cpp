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

const int N_ = 5050;
int N, T[N_];
int C[N_];
int ans[N_];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &T[i]);
	}

	for(int i = 1; i <= N; i++) {
		fill(C, C+N+1, 0);
		int best_c = 0, best_t = -1;
		for(int j = i; j <= N; j++) {
			int c = ++C[T[j]];
			if(c > best_c || (c == best_c && T[j] < best_t))
				best_c = c, best_t = T[j];
			++ans[best_t];
		}
	}

	for(int i = 1; i <= N; i++) printf("%d ", ans[i]);

    return 0;
}