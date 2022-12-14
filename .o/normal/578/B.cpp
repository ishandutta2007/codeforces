
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

const int N_ = 200500;
int N, K, X;
ll Z = 1, A[N_], P[N_], S[N_];
ll ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("578B.in", "r", stdin);
	freopen("578B.out", "w", stdout);
#endif

	scanf("%d%d%d", &N, &K, &X);
	for (int i = 1; i <= K; i++) Z = Z * X;
	for (int i = 1; i <= N; i++) scanf("%lld", A + i);
	for (int i = 1; i <= N; i++) P[i] = P[i - 1] | A[i];
	for (int i = N; i >= 1; i--) S[i] = S[i + 1] | A[i];
	for (int i = 1; i <= N; i++) ans = max(ans, P[i - 1] | S[i + 1] | (Z * A[i]));
	printf("%lld\n", ans);
	return 0;
}