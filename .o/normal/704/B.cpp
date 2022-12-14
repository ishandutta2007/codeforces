#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 5050;

int N;
ll tb[N_][N_];
ll X[N_], A[N_], B[N_], C[N_], D[N_], W[N_];
int S, E, P[N_];

/*
i -> j

|xi-xj|+ci+bj seconds if j<i.
|xi-xj|+di+aj seconds otherwise (j>i).

*/

int main() {
	scanf("%d%d%d", &N, &S, &E);
	P[S+1] = P[E+1] = 1;
	for(int i = 1; i <= N; i++) P[i] += P[i-1];

	for(int i = 1; i <= N; i++) scanf("%lld", &X[i]), W[i] = (X[i] - X[i-1]);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &C[i]);
	for(int i = 1; i <= N; i++) scanf("%lld", &D[i]);

	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N+5; j++) tb[i][j] = (ll)1e16;
	}

	if(S == 1) tb[1][1] = D[1];
	else if(E == 1) tb[1][1] = B[1];
	else tb[1][1] = D[1] + B[1];

	for(int i = 2; i <= N-1; i++) {
		if(i == S || i == E) {
			for(int b = 1; b <= N; b++) if(b + b - 1 > P[i]){ // only
				ll &t = tb[i][b];
				auto upd = [&t](ll v) { t = min(t, v); };
				upd(tb[i-1][b]   + W[i] * (b + b)     + (i == S ? C[i] : A[i]));
				upd(tb[i-1][b-1] + W[i] * (b + b - 2) + (i == S ? D[i] : B[i]));
				t -= W[i] * P[i];
			}
		}else {
			for(int b = 1; b <= N; b++) if(b + b > P[i]){
				ll &t = tb[i][b];
				auto upd = [&t](ll v) { t = min(t, v); };
				upd(tb[i-1][b+1] + W[i] * 2 * (b + 1) + A[i] + C[i]);
				upd(tb[i-1][b-1] + W[i] * 2 * (b - 1) + D[i] + B[i]);
				if(i <= S || b > 1) upd(tb[i-1][b] + W[i] * 2 * b + C[i] + B[i]);
				if(i <= E || b > 1) upd(tb[i-1][b] + W[i] * 2 * b + D[i] + A[i]);
				t -= W[i] * P[i];
			}
		}
	}

	ll ans = (ll)1e16;
	if(S == N || E == N) ans = tb[N-1][1] + W[N] + (S == N ? C[N] : A[N]);
	else ans = tb[N-1][2] + W[N] + W[N] + C[N] + A[N];

	printf("%lld\n", ans);

    return 0;
}