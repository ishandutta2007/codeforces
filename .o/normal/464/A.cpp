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

const int N_ = 1050;

int N, P;
char S[N_], T[N_];

bool first = true;
bool solve (int x) {
	if(x == N) {
		bool ret = !first;
		first = false;
		return ret;
	}
	char c = 'a';
	if(first) {
		T[x] = S[x]; c = S[x] + 1;
		if(solve(x+1)) return 1;
	}
	for(; c < 'a'+P; c++) {
		if(x-1 >= 0 && T[x-1] == c) continue;
		if(x-2 >= 0 && T[x-2] == c) continue;
		T[x] = c; 
		if(solve(x+1)) return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d%s", &N, &P, S);
	sprintf(T, S);
	puts(solve(0) ? T : "NO");

	return 0;
}