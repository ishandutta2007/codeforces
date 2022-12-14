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
typedef long double lf;
const int INF = 987654321;
const ll LINF = 1e15;

const int N_ = 2500005;
ll N, L, B;
ll P, Q;
ll D[N_];
double res;

int main() {
	int i, j, k;

	scanf("%I64d%I64d%I64d", &N, &L, &B);
	P = (B * 2) / L;
	Q = (B * 2) % L;

	res += (double)P * (double)N * (double)(N - 1) * 2;
	for(i = 1; i <= N; i++) {
		scanf("%I64d", &D[i]);
	}

	for(i = 1; i <= N; i++) D[i + N] = D[i] + L;
	for(i = 1, k = 2; i <= N; i++) {
		while(k <= 2 * N && D[k] <= D[i] + Q) ++k;
		res += (double)(k - i - 1);
	}

	for(i = 2 * N, k = 2 * N - 1; i > N; i--) {
		while(k > 0 && D[k] >= D[i] - Q) --k;
		res += (double)(i - k - 1);
	}

if(res>=(1ll<<30)) res+=100;
	printf("%.10lf\n", res / 8.);
	return 0;
}