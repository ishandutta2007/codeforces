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

const int N_ = 100005;

int N, M, K;
ll OL[N_], OR[N_], OD[N_];
ll OC[N_];
ll Res[N_], A[N_];

int main() {
    int i, j, k;

	scanf("%d%d%d", &N, &M, &K);
	for(i = 1; i <= N; i++) scanf("%I64d", &A[i]);

	for(i = 1; i <= M; i++)
		scanf("%I64d%I64d%I64d", &OL[i], &OR[i], &OD[i]);

	for(i = 1; i <= K; i++) {
		int x, y; scanf("%d%d", &x, &y);
		OC[x]++; OC[y + 1]--;
	}

	ll count = 0;
	for(i = 1; i <= M; i++) {
		count += OC[i];
		Res[OL[i]] += OD[i] * count;
		Res[OR[i] + 1] -= OD[i] * count;
	}

	ll now = 0;
	for(i = 1; i <= N; i++) {
		now += Res[i];
		printf("%I64d ", now + A[i]);
	}

    return 0;
}