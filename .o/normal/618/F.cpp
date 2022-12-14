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

const int N_ = 1000500;

int N;
int A[N_], B[N_];
ll SA[N_], SB[N_];
pii tb[N_];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", A+i);
		SA[i] = SA[i-1] + A[i];
	}
	for(int i = 1; i <= N; i++) {
		scanf("%d", B+i);
		SB[i] = SB[i-1] + B[i];
	}

	tb[0] = pii(0, 0);
	for(int i = 1; i <= N; i++) tb[i] = pii(-1, -1);

	for(int i = 1, j = 1; i <= N; i++) {
		while(j <= N && !(SA[i] <= SB[j])) ++j;
		if(j <= N) {
			ll x = SB[j] - SA[i];
			assert(0 <= x && x < N);
			pii &p = tb[x];
			if(p.first >= 0) {
				printf("%d\n", i - p.first);
				for(int x = p.first + 1; x <= i; x++) printf("%d ", x); puts("");
				printf("%d\n", j - p.second);
				for(int x = p.second +1; x <= j; x++) printf("%d ", x); puts("");
				return 0;
			}else {
				p = pii(i, j);
			}
		}
	}

	puts("-1");
    return 0;
}