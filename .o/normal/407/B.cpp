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

const int N_ = 1005;
const int MOD = (int)1e9 + 7;
int N, P[N_];
ll Table[N_];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", P+i);

	ll res = 0;

	for(int i = 1; i <= N; i++) {
		ll &t = Table[i]; t = 2;
		for(int j = P[i]; j < i; j++) t = (t + Table[j]) % MOD;
		res = (res + t) % MOD;
	}

	printf("%I64d\n", res % MOD);
	return 0;
}