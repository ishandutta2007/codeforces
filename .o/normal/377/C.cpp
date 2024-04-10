#include <stdio.h> 
#include <time.h>
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

const int N_ = 105, M_ = 20;

int N, S[N_];
int M, Q[M_];
int Table[1<<M_]; bool completed[1<<M_];

int solve (int q, int state) {
	int &ret = Table[state];
	if(completed[state]) return ret;
	completed[state] = true;

	ret = -1987654321;

	if(q == M-1) {
		if(Q[q] < 0) ret = 0;
		else { for(int i = 0; i < M; i++) if((state & (1<<i)) == 0) ret = max(ret, S[i]); }
		return ret;
	}

	int a = abs(Q[q]), b = abs(Q[q+1]);
	for(int i = 0; i < M; i++) if((state & (1<<i)) == 0) {
		int candidate = solve(q+1, state | (1<<i));
		if(a != b) candidate *= -1;
		if(Q[q] > 0) candidate += S[i];
		ret = max(ret, candidate);
	}

	return ret;
}

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 0; i < N; i++) scanf("%d", S+i);
	sort(S, S+N, greater<int>());

	scanf("%d", &M);
	for(i = 0; i < M; i++) {
		char s[5]; int t; scanf("%s%d", s, &t);
		Q[i] = (s[0] == 'p') ? t : -t;
	}

	int res = solve(0, 0);
	if(Q[0] == 2 || Q[0] == -2) res = -res;
	printf("%d\n", res);
	return 0;
}