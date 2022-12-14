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

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 100500;
int N, A[N_];

set<int> S;
bool good (int bound) {
	S.clear();
	for(int i = 1; i <= N; i++) {
		if(A[i] <= bound) S.insert(A[i]);
	}
	for(int i = N; i >= 1; i--) if(A[i] > bound) {
		bool chk = false;
		for(int x = A[i]; x > 0 && !chk; x >>= 1) {
			if(x <= bound && S.find(x) == S.end()) {
				S.insert(x);
				chk = true;
			}
		}
		if(!chk) return false;
	}
	return true;
}
int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", A+i);
	}
	sort(A+1, A+N+1);

	int low = 1, high = (int)1e9, ans = (int)1e9;
	while(low <= high) {
		int mid = (low + high) >> 1;
		if(good(mid)) {
			high = mid - 1;
			ans = mid;
		}else {
			low = mid + 1;
		}
	}

	good(ans);
	for(auto x : S) printf("%d ", x);

    return 0;
}