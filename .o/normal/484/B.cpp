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

const int N_ = 200500;
int N, A[N_];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", A+i);
	sort(A, A+N);
	N = unique(A, A+N) - A;


	int ans = 0;
	for(int i = 0; i < N; i++) {
		int x = A[i];
		for(int t = x; t <= (int)1e6; t += x) {
			// y mod x = y - t
			int p = upper_bound(A, A+N, t + x - 1) - A - 1;
			if(0 <= p && p < N) {
				if(t <= A[p] && A[p] < t + x) {
					ans = max(ans, A[p] % x);
				}
			}
		}
	}

	printf("%d\n", ans);
    return 0;
}