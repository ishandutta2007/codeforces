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

int N, K, L, R, Sall, Sk;

int main() {
	int i, j, k;


	scanf("%d%d%d%d%d%d", &N, &K, &L, &R, &Sall, &Sk);
	
	// Sall - Smin  K  
	//   K   Sk

	//  N-K 
	int Slow = Sall - Sk;
	for(i = 0; i < N-K; i++) printf("%d ", Slow/(N-K) + (i<Slow%(N-K)));

	//  K 
	for(i = 0; i < K; i++) printf("%d ", Sk/K + (i<Sk%K));
	return 0;
}