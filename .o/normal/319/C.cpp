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

const int N_ = 100005;

int N, A[N_], B[N_];
deque<int> deq;
ll Table[N_];

ll val (int id, ll x) {
	return Table[id] + (ll)B[id] * x;
}

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", A+i);
	for(i = 1; i <= N; i++) scanf("%d", B+i);

	Table[1] = 0;
	deq.push_back(1);
	for(i = 2; i <= N; i++) {
		while(deq.size() >= 2 && val(deq.front(), A[i]) > val(*++deq.begin(), A[i])) deq.pop_front();
		Table[i] = val(deq.front(), A[i]);
		while(deq.size() >= 2 && 
			(llf)(Table[deq.back()] - Table[*++deq.rbegin()]) / (B[*++deq.rbegin()] - B[deq.back()])
			> (llf)(Table[i] - Table[*++deq.rbegin()]) / (B[*++deq.rbegin()] - B[i])
		) deq.pop_back();
		deq.push_back(i);
	}

	printf("%lld\n", Table[N]);

	return 0;
}