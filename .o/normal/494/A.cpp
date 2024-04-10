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

const int N_ = 200500;
char S[N_];
int N;
int V[N_];

int main() {
	scanf("%s", S + 1); N = strlen(S + 1);

	int pos = -1;
	for (int i = 1; i <= N; i++) {
		V[i] += V[i - 1];
		if (S[i] == '(') V[i]++; else if (S[i] == ')') V[i]--; else pos = i, V[i]--;
		if (V[i] < 0) return 0 & puts("-1");
	}

	int t = 0;
	for (int i = 1; i <= N; i++) {
		if (S[i] == '(') t++; else if (S[i] == ')') t--; else {
			--t;
			if (i == pos) t -= V[N];
		}
		if (t < 0) return 0 & puts("-1");
	}

	for (int i = 1; i <= N; i++) {
		if (S[i] == '#') printf("%d\n", (i == pos) ? 1 + V[N] : 1);
	}


	return 0;
}