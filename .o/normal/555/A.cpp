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

int N, M;

int main() {
#ifndef ONLINE_JUDGE
	freopen("555A.in", "r", stdin);
	freopen("555A.out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int n; scanf("%d", &n);

		int c = 0;
		for (int j = 1; j <= n; j++) {
			int a; scanf("%d", &a);
			if (a == c + 1) c++;
		}

		if (c > 0) {
			printf("%d\n", N - M + N - c - c + 1);
			return 0;
		}
	}

	return 0;
}