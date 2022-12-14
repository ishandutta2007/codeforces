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
#include <time.h>
#include <functional>
#include <numeric>
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 205, K_ = 1050;

int N, K, A[N_];

const ll MOD = (ll)1e9 + 7;
struct mint {
	int val;
	mint(ll val = 0): val((val + MOD) % MOD) { }
	mint operator+(mint p) { return ((ll)val + (ll)p.val) % MOD; }
	mint operator-(mint p) { return ((ll)val % (ll)p.val) % MOD; }
	mint operator*(mint p) { return ((ll)val * (ll)p.val) % MOD; }
};

mint tb[N_][N_][K_];

void upd (mint &t, mint v) {
	t = t + v;
}
int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	sort(A+1, A+N+1);
	A[N+1] = A[N];
	A[0] = A[1];

	tb[1][0][0] = 1;
	for(int i = 1; i <= N; i++) {
		int d = (A[i+1] - A[i]);
		for(int j = 0; j < i; j++) {
			int v = j * d;
			for(int k = 0; k <= K; k++, v++) {
				if(j > 0 && v-d <= K) upd(tb[i+1][j-1][v-d], tb[i][j][k] * j);
				if(v <= K) upd(tb[i+1][j][v], tb[i][j][k] * (j+1));
				if(v+d <= K) upd(tb[i+1][j+1][v+d], tb[i][j][k]);
			}
		}
	}
	mint ans = 0;
	for(int k = 0; k <= K; k++) upd(ans, tb[N+1][0][k]);
	printf("%d\n", ans.val);
    return 0;
}