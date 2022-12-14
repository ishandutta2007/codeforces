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
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 1000500;

int N, M;
int f[N_], q[N_], h[N_];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &f[i]);

	for(int i = 1; i <= N; i++) {
		int x = f[i];
		if(!q[x]) {
			M += 1;
			q[x] = M;
			h[M] = x;
		}

		if(f[x] != x) {
			return 0 & puts("-1");
		}
	}


	printf("%d\n", M);
	for(int i = 1; i <= N; i++) printf("%d%c", q[f[i]], i+1 <= N ? ' ' : '\n');
	for(int i = 1; i <= M; i++) printf("%d%c", h[i], i+1 <= M ? ' ' : '\n');
  return 0;
}