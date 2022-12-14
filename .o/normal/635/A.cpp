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

int R, C, N, K;
int chk[50][50];
int sum[50][50];

int get(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
}

int main() {
	scanf("%d%d%d%d", &R, &C, &N, &K);
	while(N--) {
		int x, y; scanf("%d%d", &x, &y);
		chk[x][y] = 1;
	}
	for(int i = 1; i <= R; i++)
		for(int j = 1; j <= C; j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + chk[i][j];

	int ans = 0;
	
	for(int x1 = 1; x1 <= R; x1++)
		for(int x2 = x1; x2 <= R; x2++)
			for(int y1 = 1; y1 <= C; y1++)
				for(int y2 = y1; y2 <= C; y2++)
					if(get(x1, y1, x2, y2) >= K) ++ans;

	printf("%d\n", ans);			
    return 0;
}