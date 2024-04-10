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

int N, A[105];
vector<int> S[3];

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", A+i);
	sort(A+1, A+N+1);

	int minus = 0;
	for(i = 1; i <= N; i++) if(A[i] < 0) ++minus;

	S[0].push_back(A[1]);
	for(i = N; i >= 2; i--) S[A[i] ? 1 : 2].push_back(A[i]);
	if(minus % 2 == 0) {
		S[2].push_back(S[1].back());
		S[1].pop_back();
	}

	for(i = 0; i < 3; i++) {
		printf("%d ", S[i].size());
		for(j = 0; j < S[i].size(); j++) printf("%d%c", S[i][j], (j == S[i].size()-1) ? '\n' : ' ');
	}

	return 0;
}