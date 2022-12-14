
#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 200500;

lf ans = 2e18;
int N, A[N_];

int main() {
#ifndef ONLINE_JUDGE
	freopen("578C.in", "r", stdin);
	freopen("578C.out", "w", stdout);
#endif

	scanf("%d", &N);//if(N>310)return 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", A + i);
	}

	lf low = *min_element(A + 1, A + N + 1);
	lf high = *max_element(A + 1, A + N + 1);
	for (int rep = 0; rep < 100; rep++) {
		lf mid = (low + high) / 2;
		lf cur_min = 2e18, cur_max = -2e18;
		lf cur_sum_min = 0, cur_sum_max = 0;
		for (int i = 1; i <= N; i++) {
			lf a = A[i] - mid;
			if (cur_sum_max < 0) cur_sum_max = 0;
			if (cur_sum_min > 0) cur_sum_min = 0;
			cur_sum_min += a;
			cur_sum_max += a;
			cur_max = max(cur_max, cur_sum_max);
			cur_min = min(cur_min, cur_sum_min);
		}
		cur_min = abs(cur_min);
		cur_max = abs(cur_max);
		ans = min(ans, max(cur_min, cur_max));
		if (cur_min < cur_max) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	printf("%.20lf\n", ans);
	return 0;
}