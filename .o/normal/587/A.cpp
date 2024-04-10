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

int N, C[1000500];

int main() {
#ifndef ONLINE_JUDGE
	freopen("587A.in", "r", stdin);
	freopen("587A.out", "w", stdout);
#endif
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		++C[x];
	}

	int ans = 0;
	for (int i = 0; i < 1000300; i++) {
		C[i + 1] += C[i] / 2;
		C[i] %= 2;
		ans += C[i];
	}

	printf("%d\n", ans);
	return 0;
}