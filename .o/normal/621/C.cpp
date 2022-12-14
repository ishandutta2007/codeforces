#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
typedef double lf;

const int N_ = 100500;
int N, P;
int L[N_], R[N_];
ll A[N_], B[N_];

int main() {
	scanf("%d%d", &N, &P);
	for(int i = 0; i < N; i++) {
		scanf("%d%d", L+i, R+i);
		A[i] = R[i] / P - (L[i] - 1) / P;
		B[i] = R[i] - L[i] + 1;
	}
	lf ans = 0;
	for(int i = 0; i < N; i++) {
		ans += (lf)A[i] / B[i] * 4;
		ans -= ((lf)A[i] * A[(i+1)%N]) / ((lf)B[i] * B[(i+1)%N]) * 2;
	}
	printf("%lf\n", ans * 1000);

    return 0;
}