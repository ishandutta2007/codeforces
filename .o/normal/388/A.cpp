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

const int N_ = 105;
int N, D[N_];
bool Chk[N_];
int res;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	sort(D+1, D+N+1);

	while(1) {
		int t = 0;
		for(int i = 1; i <= N; i++) if(!Chk[i] && t <= D[i]) ++t, Chk[i] = 1;
		if(t > 0) ++res; else break;
	}

	printf("%d\n", res);

	return 0;
}