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
#include <unordered_set>
 #include <cfloat>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
 
#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 105;

int N, M, X, Y;

int len (int x) {
	for(int l = 1, v = 7; ; l++) {
		if(v >= x) return l;
		v *= 7;
	}
}

set<ll> S;

bool chk[100];

void dfs (int i, ll p, ll q) {
	if(p >= N || q >= M) return;
	if(i == X+Y) {
		S.insert(p * (ll)1e9 + q);
		return;
	}
	for(int d = 0; d < 7; d++) {
		if(!chk[d]) {
			chk[d] = true;
			((i < X ? p : q) *= 7) += d;
			dfs(i + 1, p, q);
			((i < X ? p : q) -= d) /= 7;
			chk[d] = false;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	X = len(N), Y = len(M);
	if(X + Y > 7) return 0 & puts("0");

	dfs(0,0,0);

	printf("%lu\n", S.size());
	return 0;
}