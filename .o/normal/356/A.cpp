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

const int N_ = 300005, M_ = 300005;
const int LEAF = 524288;
int N, M;
int A[M_];
vector<int> Q[M_];
multiset<int> P;

int main() {
	int i, j, k;

	scanf("%d%d", &N, &M);
	
	for(k = 1; k <= M; k++) {
		int l, r; scanf("%d%d%d", &l, &r, &A[k]);
		if(l < A[k]) {
			Q[l].push_back(k);
			Q[A[k]].push_back(-k);
		}
		if(A[k]+1 < r+1) {
			Q[A[k]+1].push_back(k);
			Q[r+1].push_back(-k);
		}
	}

	for(i = 1; i <= N; i++) {
		for(j = 0; j < Q[i].size(); j++) {
			int v = Q[i][j];
			if(v > 0) P.insert(v); else P.erase(-v);
		}
		if(!P.empty()) printf("%d ", A[*P.begin()]);
		else printf("0 ");
	}
	return 0;	
}