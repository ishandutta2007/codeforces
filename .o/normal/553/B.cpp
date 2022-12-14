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

int N; ll K;
ll fib[55];

int main() {

	scanf("%d%I64d", &N, &K);

	fib[1] = 1;
	for (int i = 2; i <= N; i++) fib[i] = fib[i - 1] + fib[i - 2];

	int off = 0;
	for (int i = 1; i <= N; i++) {
		if (K > fib[N-i+1]) {
			K -= fib[N - i + 1];
			off = 1;
		}
		printf("%d ", i + off);
		if(off < 0) off = 0; else if(off > 0) off = -1;
	}
	return 0;
}