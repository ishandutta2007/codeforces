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

const int N_ = 150005, M_ = 305;

int N, M, D, DD;
int A[M_], B[M_], T[M_];

ll Table[2][N_];
ll sumB;

struct state {
	ll v; int x; 
	state(ll v = 0, int x = 0): v(v), x(x) { }
};

deque<state> deq;

int main() {
	int i, j, k;

	scanf("%d%d%d", &N, &M, &D);
	for(i = 1; i <= M; i++) {
		scanf("%d%d%d", &A[i], &B[i], &T[i]);
		sumB += B[i];
	}

	for(k = 1; k <= N; k++) Table[1][k] = abs(A[1] - k);

	for(i = 2; i <= M; i++) {
		int x = i & 1;
		ll m = (ll)D * (T[i] - T[i-1]);

		while(!deq.empty()) deq.pop_back();

		for(j = 1; j <= m && j <= N; j++) {
			while(!deq.empty() && deq.back().v >= Table[!x][j]) deq.pop_back();
			deq.push_back(state(Table[!x][j], j));
		}

		for(j = 1; j <= N; j++) {
			while(!deq.empty() && deq.front().x < j - m) deq.pop_front();
			if(j + m <= N) {
				while(!deq.empty() && deq.back().v >= Table[!x][j+m]) deq.pop_back();
				deq.push_back(state(Table[!x][j+m], j+m));
			}
			Table[x][j] = deq.front().v + abs(j - A[i]);
		}
	}

	ll res = (ll)1e15;
	for(i = 1; i <= N; i++) if(res > Table[M%2][i]) res = Table[M%2][i];
	printf("%I64d\n", sumB - res);
	return 0;
}