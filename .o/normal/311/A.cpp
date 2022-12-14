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

int N, K;

int main() {
	int i, j, k;

	scanf("%d%d", &N, &K);
	if(N * (N-1) / 2 <= K) {
		puts("no solution");
	}else {
		for(i = 0; i < N; i++) printf("0 %d\n", i);
	}

	return 0;
}