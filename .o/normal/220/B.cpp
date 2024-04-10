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
const int M_ = 100005;

int N, M, K;
int A[N_];

struct Query {
	int l, r, x;
	Query(int l = 0, int r = 0, int x = 0): l(l), r(r), x(x) { }
	bool operator< (const Query &q) const { return (l-1)/K != (q.l-1)/K ? (l-1)/K < (q.l-1)/K : r < q.r; }
} Q[M_];

int C[N_], T[N_], W[N_];
int Res[M_];

int main() {
	int i, j, k;
	
	scanf("%d%d", &N, &M);
	for(i = 1; i <= N; i++) scanf("%d", A+i);
	for(i = 1; i <= M; i++) {
		scanf("%d%d", &Q[i].l, &Q[i].r);
		Q[i].x = i;
	}
	
	K = (int)sqrt(N);
	sort(Q+1, Q+M+1);


	for(int l = 1, q = 1; l <= N && q <= M; l += K) {
		for(i = 1; i <= N; i++) C[i] = 0;

		int now = 0;

		for(i = l; i <= N; i++) {
			if(A[i] <= N) {
				++C[A[i]];
				if(C[A[i]] == A[i]) ++now;
				else if(C[A[i]] == A[i]+1) --now;
			}

			for(; q <= M && Q[q].l < l+K && Q[q].r == i; ++q) {
				int &ret = Res[Q[q].x];
				ret = now;
				for(j = l; j < Q[q].l; j++) {
					int a = A[j];
					if(a > N) continue;
					if(W[a] != q) { W[a] = q; T[a] = 1; }
					else ++T[a];
					if(C[a] - T[a] == a - 1) --ret;
					else if(C[a] - T[a] == a) ++ret;
				}
			}
  		}
 	}

	for(i = 1; i <= M; i++) printf("%d\n", Res[i]);
	return 0;
}