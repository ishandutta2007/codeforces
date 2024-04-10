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

int N, K, C[2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("549C.in", "r", stdin);
	freopen("549C.out", "w", stdout);
#endif

	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		int a; scanf("%d", &a);
		C[a % 2] ++;
	}

	int x = C[0], y = C[1];
	int turns = N - K;
	int my = turns / 2;

	char ans;

	if (turns == 0) {
		ans = (y % 2) ? 'S' : 'D';
	}
	else if (turns % 2 == 1) {
		if (my >= y || (my >= x && K % 2 == 0)) ans = 'D';
		else ans = 'S';
	}
	else {
		if (my >= x && K % 2 == 1) ans = 'S';
		else ans = 'D';
	}

	puts((ans == 'S') ? "Stannis" : "Daenerys");


	return 0;
}