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
	freopen("559A.in", "r", stdin);
	freopen("559A.out", "w", stdout);
#endif

	int a1, a2, a3, a4, a5, a6;
	scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);

	printf("%d\n", (a1 + a2 + a3) * (a1 + a2 + a3) - (a1 * a1 + a3 * a3 + a5 * a5));

	return 0;
}