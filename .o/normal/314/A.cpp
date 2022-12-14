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

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

inline int getint() {
	int n; scanf("%d", &n);
	return n;
}

inline ll getll() {
	ll n; scanf("%I64d", &n);
	return n;
}

const int N_ = 200005;

int N;
ll K, A[N_]; 
bool chk[N_];
ll sum, out;

int main() {
	int i, j, k;

	scanf("%d%I64d", &N, &K);
	for(i = 0; i < N; i++) {
		scanf("%I64d", A+i);
		ll v = sum - (N - i - 1) * A[i] * (i - out);
		if(v < K) {
			chk[i] = 1;
			++out;
			printf("%d\n", i + 1);
		}else {
			sum += A[i] * (i - out);
		}
	}
	return 0;
}