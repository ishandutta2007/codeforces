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

using namespace std;
typedef long long ll;
const int INF = 987654321;
const ll LINF = 1e15;

const int N_ = 100005;

bool Ck[N_];
int N;
int A[N_],B[N_],C[N_];

int main() {
	int i, j, k;

	scanf("%d", &N);
	
	for(i = 0; i < N; i++) A[i]=i;
	for(i = 0; i < N; i++) B[i]=(i+1)%N;

	for(i = 0; i < N; i++) { 
		C[i]=(A[i]+B[i])%N;
		if(Ck[C[i]]) return 0 & puts("-1");
		Ck[C[i]]=1;
	}
	
	for(i = 0; i < N; i++) printf("%d ", A[i]); puts("");
	for(i = 0; i < N; i++) printf("%d ", B[i]); puts("");
	for(i = 0; i < N; i++) printf("%d ", C[i]);
	return 0;
}