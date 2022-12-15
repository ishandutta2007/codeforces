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

const int N_ = 150005, M_ = 150005;

int N, M, C[N_][3];
char S[N_];

int main() {
	int i, j, k;

	scanf("%s", S+1);
	N = strlen(S+1);

	for(i = 1; i <= N; i++) {
		for(j = 0; j < 3; j++) C[i][j] += C[i-1][j];
		++C[i][S[i] - 'x'];
	}

	scanf("%d", &M);
	while(M--) {
		int l, r; scanf("%d%d", &l, &r);
		int s = (int)1e7, b = -1;
		for(i = 0; i < 3; i++) { 
			int v = C[r][i] - C[l-1][i];
			b = max(b, v);
			s = min(s, v);
		}

		puts((r-l+1 < 3 || b-s < 2) ? "YES" : "NO");

	}
	return 0;
}