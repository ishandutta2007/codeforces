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
int N; ll L, R, QL, QR;
ll A[N_], sum;
ll res;

int main() {
	int i, j, k;

	scanf("%d%d%d%d%d", &N, &L, &R, &QL, &QR);
	for(i = 0; i < N; i++) scanf("%d", A+i), sum += A[i];

	ll suml = 0, sumr = sum;
	for(i = 0; i <= N; i++) {
		ll tmp = QL * max(i+i-N-1,0) + QR * max(N-i-i-1, 0) + suml * L + sumr * R;
		if(i == 0 || res > tmp) res = tmp;
		suml += A[i];
		sumr -= A[i];
	}

	printf("%lld\n", res);

	return 0;	
}