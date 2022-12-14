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

const int N_ = 200500;
int N, X[N_];
ll sumX[N_]; // <= 2 * 10^5 * 10^6 = 2 * 10^11
// 10^11 * 10^5 = 10^16 < 10^18

ll opt (int m, int r) {
	return (sumX[m] - sumX[m-1-r]) + (sumX[N] - sumX[N-r]);
}

ll ans_p = 0, ans_q = 1;
int ans_m = 1, ans_r = 0;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", X+i);
	sort(X+1, X+N+1);
	for(int i = 1; i <= N; i++) sumX[i] = sumX[i-1] + X[i];

	for(int m = 2; m <= N-1; m++) {
		int low = 1, high = min(m-1, N-m);
		int r = -1;
		while(low <= high) {
			int mid = (low + high) >> 1;
			// if(opt(m, mid-1) / (2*mid-1) < opt(m, mid) / (2*mid+1))
			if(opt(m, mid-1) * (2*mid+1) < opt(m, mid) * (2*mid-1)) {
				r = mid;
				low = mid+1;
			}else {
				high = mid-1;
			}
		}

		if(r < 0) continue;

		ll q = 2 * r + 1; // 2 * 10^5
		ll p = opt(m, r) - q * X[m]; // 2 * 10^11
		// if(p / q > ans_p / ans_q)
		if(p * ans_q > q * ans_p) {
			tie(ans_p, ans_q, ans_m, ans_r) = tie(p, q, m, r);
		}
	}
	
	assert(ans_m > 0);

	printf("%d\n%d", ans_r + ans_r + 1, X[ans_m]);
	for(int i = 1; i <= ans_r; i++)
		printf(" %d %d", X[ans_m - i], X[N - i + 1]);
	puts("");
    return 0;
}