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

const int N_ = 500505;
int N, A[N_];
int res;

bool possible (int x) {
	int i, j, k;

	for(i = N, j = N - x; j > 0; i--, j--) {
		if(A[j] * 2 > A[i]) return false;
	}

	return true;
}

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", A+i);
	sort(A+1, A+N+1);

	int low = (N+1)/2;
	int high = N;
	res = N;

	while(low * 2 < N) ++low;

	while(low <= high) {
		int mid = (low + high) >> 1;
		if(possible(mid)) {
			res = mid;
			high = mid - 1;
		}else {
			low = mid + 1;
		}
	}

	printf("%d\n", res);
	return 0;
}