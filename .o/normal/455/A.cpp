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

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N;
int C[100005];
ll Table[100005];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) { int v; scanf("%d", &v); ++C[v]; }

	Table[1] = C[1];
	Table[2] = C[2]*2;
	for(int i = 3; i <= (int)1e5; i++) Table[i] = max(Table[i-2], Table[i-3]) + (ll)C[i]*i;
	printf("%I64d\n", max(Table[(int)1e5], Table[(int)1e5 - 1]));
	return 0;
}