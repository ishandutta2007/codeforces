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

const int S = (int)1e6;
const int N_ = 500005;

int N, X[N_], A, M;
int V[S+15];

int main() {

	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", X+i), V[X[i]] = 1;

	for(int i = 1; i <= S/2; i++) {
		int j = S+1-i;
		if(V[i] && V[j]) ++A;
		else if(V[i]) ++M, V[j] = 2;
		else if(V[j]) ++M, V[i] = 2;
	}

	
	for(int i = 1; i <= S/2 && A > 0; i++) {
		int j = S+1-i;
		if(!V[i] && !V[j]) V[i] = V[j] = 2, M += 2, --A;
	}

	printf("%d\n" ,M);
	for(int i = 1; i <= S; i++) if(V[i] == 2) printf("%d ", i);

	return 0;
}