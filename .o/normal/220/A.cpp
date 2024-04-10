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

const int N_ = 100005;

int N;
int A[N_], B[N_];

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		scanf("%d", A+i);
		B[i] = A[i];
	}

	sort(B+1, B+N+1);

	int t = 0;

	for(i = 1; i <= N; i++) {
		if(B[i] != A[i]) ++t;
	}

	puts(t <= 2 ? "YES" : "NO");
	return 0;
}