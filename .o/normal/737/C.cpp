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

const int N_ = 200500;

int N, S;
int A[N_];
int ans;

int cnt[N_], sum[N_];

int main() {
	scanf("%d%d", &N, &S);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	swap(A[1], A[S]);


	for(int i = 2; i <= N; i++)
		cnt[A[i]] += 1;

	for(int a = 1; a <= N; a++)
		sum[a] += sum[a-1] + cnt[a];

	int blank = 0;
	ans = N-1;
	for(int b = 1, i = 1; b < N; b++) {
		// a_i \in [0, b]    
		if(cnt[b] == 0) blank += 1;
		for(; i <= sum[b]; i++) {
			int cand = cnt[0] + sum[N] - i;
			if(cand >= blank) ans = min(ans, cand);
		}
	}


	if(A[1] > 0) ans++;

	printf("%d\n", ans);
    return 0;
}