
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

int N;
int X[N_], Y[N_], C[N_];
int main() {
#ifndef ONLINE_JUDGE
	freopen("573A.in", "r", stdin);
	freopen("573A.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		while (x % 2 == 0) {
			++X[i]; x /= 2;
		}
		while (x % 3 == 0) {
			++Y[i]; x /= 3;
		}
		C[i] = x;
	}

	for (int i = 1; i <= N; i++) {
		if (C[i] != C[1]) return 0 & puts("No");
	}
	puts("Yes");
	return 0;
}