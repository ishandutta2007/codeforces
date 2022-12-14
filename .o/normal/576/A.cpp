
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

int N, K;
bool good[1050];

int main() {
#ifndef ONLINE_JUDGE
	freopen("576A.in", "r", stdin);
	freopen("576A.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		bool isp = true;
		for (int j = 2; j < i; j++) if (i % j == 0) {
			isp = false;
			int x = i;
			while (x % j == 0) x /= j;
			if (x == 1) good[i] = true;
			break;
		}
		if (isp) good[i] = true;
		if (good[i]) ++K;
	}
	printf("%d\n", K);
	for (int i = 2; i <= N; i++) if (good[i])printf("%d ", i);
	return 0;
}