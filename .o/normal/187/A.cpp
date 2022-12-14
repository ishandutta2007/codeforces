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

const int N_ = 200005;
int N, A[N_], B[N_];
ll res;

int par[N_], size[N_];
int get (int x) { return (par[x] == x) ? x : (par[x] = get(par[x])); }

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", A+i);
	for(i = 1; i <= N; i++) scanf("%d", &k), B[k] = i;
	for(i = 1; i <= N; i++) A[i] = B[A[i]];

	for(i = 1; i <= N; i++) if(A[i] < A[i-1]) break;
	printf("%d\n", N-i+1);

	return 0;
}