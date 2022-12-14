#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N;
char D[105][105];
int T[105];
int A[105];

bool chk[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("549B.in", "r", stdin);
	freopen("549B.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%s", D[i] + 1);
	for (int i = 1; i <= N; i++) scanf("%d", A + i);

	for (int rep = 1; rep <= 1000; rep++) {
		for (int i = 1; i <= N; i++) if (!chk[i] && T[i] == A[i]) {
			for (int x = 1; x <= N; x++) if (D[i][x] == '1') ++T[x];
			chk[i] = true;
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) if (chk[i]) ++ans;
	printf("%d\n", ans);
	for (int i = 1; i <= N; i++) if (chk[i]) printf("%d ", i);

	return 0;
}