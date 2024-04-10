
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
int T[205][205];
char S[205];

int main() {
#ifndef ONLINE_JUDGE
	freopen("549D.in", "r", stdin);
	freopen("549D.out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%s", S +1);
		for (int j = 1; j <= M; j++) T[i][j] = (S[j] == 'W') ? +1 : -1;
	}

	int ans = 0;
	for (int i = N; i > 0; i--) for (int j = M; j > 0; j--) {
		if (T[i][j] == 0) continue;
		int val = T[i + 1][j] + T[i][j + 1] - T[i + 1][j + 1];
		if (val != T[i][j]) ans++;
	}

	printf("%d\n", ans);

	return 0;
}