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

const int N_ = 25;

int N, M;

struct S {
    int k, v;
    S(): v(0), k(0) { }
    S(int k, int v): v(v), k(k) {}
    bool operator < (const S &t) const { return v > t.v; }
};

priority_queue <S> PQ;
int A[N_], B[N_];
int mark[N_];

ll T[N_];
ll res;

int main() {
	int i, j, k;

	scanf("%d%d", &N, &M);
	for(i = 0; i < N; i++) scanf("%d", A+i);
	for(i = 0; i < N; i++) scanf("%d", B+i);

	int depth = 0;
	ll cost = 0;
	ll tmp=0;
	for(i = 0, j = 0; i < N+N+N; i++, j = (j<N-1) ? (j+1) : 0) {
		--depth;
		if(!mark[j]++) PQ.push( S(j, A[j] - B[j]) );
		cost += B[j];

		if(depth < 0) {
			S t = PQ.top();
			if(!--mark[t.k]) PQ.pop();
			cost += t.v;
			depth += 2;
		}
			
		if((i+1)%N == 0) {
			T[i/N] = cost;
		}
	}

	res += (-T[0] + T[2]) * (M / 2 - 1);
	res += T[1];

	printf("%I64d\n", res);
	return 0;
}