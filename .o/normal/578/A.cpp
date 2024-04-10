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
	freopen("578A.in", "r", stdin);
	freopen("578A.out", "w", stdout);
#endif

	int a, b; scanf("%d%d", &a, &b);
	if (a < b) return 0 & puts("-1");
	
	lf ans = 0;
	int x = a / b, y = a % b;
	if (x % 2 == 1) {
		ans = (lf)y / (x + 1) + b;
	}
	else {
		ans = (lf)(y + b) / x + b;
	}

	printf("%.19lf\n", ans);
	return 0;
}