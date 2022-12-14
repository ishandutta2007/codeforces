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

char S[100005];
int N;

char tmp[100500];

const int N_ = 100005;
int D[N_];
string T[N_];

ll A[10], B[10];
const int MOD = (int)1e9 + 7;

int main() {
	scanf("%s%d", S, &N);
	for(int i = 1; i <= N; i++) {
		scanf("%s", tmp);
		D[i] = tmp[0] - '0';
		T[i] = (tmp + 3);
	}

	for(int i = 0; i <= 9; i++) {
		A[i] = 10;
		B[i] = i;
	}

	for(int i = N; i > 0; i--) {
		ll a = 1, b = 0;
		for(int j = 0; j < T[i].size(); j++) {
			int t = T[i][j] - '0';
			a = (A[t] * a) % MOD;
			b = (A[t] * b + B[t]) % MOD;
		}
		A[D[i]] = a;
		B[D[i]] = b;
	}

	ll res = 0;
	for(int i = -1; S[++i]; ){
		int t = S[i] - '0';
		res *= A[t]; res %= MOD;
		res += B[t]; res %= MOD;
	}

	printf("%lld\n", res);

	return 0;
}