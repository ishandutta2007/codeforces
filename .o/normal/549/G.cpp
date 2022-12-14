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

int N, A[N_];

int main() {
#ifndef ONLINE_JUDGE
	freopen("549G.in", "r", stdin);
	freopen("549G.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		A[i] = a + i;
	}
	sort(A + 1, A + N + 1);
	for (int i = 1; i <= N; i++) A[i] -= i;

	if (is_sorted(A + 1, A + N + 1)){
		for (int i = 1; i <= N; i++) printf("%d ", A[i]);
	}
	else {
		puts(":(");
	}
	return 0;
}