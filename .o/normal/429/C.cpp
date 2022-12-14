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

const int N_ = 25;

int N, C[N_], T[N_];

void QUIT (bool r) {
	puts(r ? "YES" : "NO");
	exit(0);
}

bool solve (int);

bool solve2 (int s1, int s2, vector<int>& a, int c) {
	if(s1 == 0) {
		if(c < 2) return false;
		for(int i = 0; i < c; i++) if(!solve(a[i])) return false;
		return true;
	}

	if(s1 < s2) s2 = s1;

	for(int x = s2; x >= 1; x--) if(T[x] > 0) {
		--T[x]; a[c] = x;
		if(solve2(s1 - x, x, a, c+1)) return true;
		++T[x]; a[c] = 0;
	}

	return false;
}

bool solve (int sz) {
	if(sz == 1) return true;
	if(sz == 2) return false;
	vector<int> a(N+2);
	return solve2 (sz - 1, sz - 2, a, 0);
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", C+i), ++T[C[i]];

	if(T[N] != 1) QUIT(0);
	--T[N];
	QUIT(solve(N));
	return 0;
}