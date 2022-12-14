
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

const int N_ = 100500;
int N, H[N_], A[N_], B[N_];

int main() {
#ifndef ONLINE_JUDGE
	freopen("573B.in", "r", stdin);
	freopen("573B.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", H + i);

	for (int i = 1; i <= N; i++) A[i] = min(A[i - 1] + 1, H[i]);
	for (int i = N; i > 0; i--)  B[i] = min(B[i + 1] + 1, H[i]);

	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, min(A[i], B[i]));
	printf("%d\n", ans);
	return 0;
}