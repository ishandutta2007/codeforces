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

const int N_ = 1005;

int N;
map<int, int> Count;
int res;

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		int d; scanf("%d", &d);
		if(d == 0) continue;
		Count[d]++;
		if(Count[d] > 2) return 0 & puts("-1");
		else if(Count[d] == 2) ++res;
	}

	printf("%d\n", res);

	return 0;
}