
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("549F.in", "r", stdin);
	freopen("549F.out", "w", stdout);
#endif
	int N;  scanf("%d", &N);

	if (N < 4) return 0 & puts("NO");

	puts("YES");
	if (N % 2 == 0) {
		puts("1 * 2 = 2");
		puts("3 * 4 = 12");
		puts("2 * 12 = 24");
		for (int i = 6; i <= N; i += 2) printf("%d - %d = %d\n", i, i - 1, 1);
		for (int i = 0; i < N / 2 - 2; i++) puts("24 * 1 = 24");
	}
	else {
		puts("3 + 2 = 5");
		puts("4 * 5 = 20");
		puts("20 + 5 = 25");
		puts("25 - 1 = 24");
		for (int i = 7; i <= N; i += 2) printf("%d - %d = %d\n", i, i - 1, 1);
		for (int i = 0; i < (N - 5) / 2; i++) puts("24 * 1 = 24");
	}

	return 0;
}