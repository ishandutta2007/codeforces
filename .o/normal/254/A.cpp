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

int N, A[600005], X[600005];
bool cmp (const int &a, const int &b) { return A[a] < A[b]; }

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, j, k;

	scanf("%d", &N);
	for(i = 0; i < N+N; i++) scanf("%d", A+i), X[i] = i;
	sort(X, X+N+N, cmp);

	for(i = 0; i < N+N; i += 2) {
		if(A[X[i]] != A[X[i+1]]) return 0 & puts("-1");
	}

	for(i = 0; i < N+N; i += 2) {
		printf("%d %d\n" ,X[i]+1, X[i+1]+1);
	}

	return 0;
}