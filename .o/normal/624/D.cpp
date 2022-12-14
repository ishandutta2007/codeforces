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

#define debug(format, ...) printf(format, __VA_ARGS__);

int N, A, B;
const int N_ = 1000500;
int D[N_];

ll ans = (ll)1e18;

ll pref[N_], suff[N_];

set<int> S[2];
void solve2 (int p, int t) {
	if(S[t].find(p) != S[t].end()) return;
	S[t].insert(p);
	for(int i = 1; i <= N; i++) {
		if(D[i] % p == 0) pref[i] = pref[i-1]; 
		else if(D[i] % p == 1 || D[i] % p == p-1) pref[i] = pref[i-1] + B;
		else pref[i] = (ll)1e18;
	}
	for(int i = N; i > 0; i--) {
		if(D[i] % p == 0) suff[i] = suff[i+1]; 
		else if(D[i] % p == 1 || D[i] % p == p-1) suff[i] = suff[i+1] + B;
		else suff[i] = (ll)1e18;
	}
	if(t == 0) {
		for(int i = N; i > 0; i--) suff[i] = min(suff[i], suff[i+1] + A);
	}else {
		for(int i = 1; i <= N; i++) pref[i] = min(pref[i], pref[i-1] + A);
	}
	for(int i = 1; i-1 <= N; i++) {
		ans = min(ans, pref[i-1] + suff[i]);
	}
}

void solve1 (int x, int t) {
	vector<int> ret;
	if(x <= 1) return;
	for(int i = 2; i * i <= x; i++) {
		if(x % i == 0) {
			solve2(i, t);
		}
		while(x % i == 0) x /= i;
	}
	if(x > 1) {
		solve2(x, t);
	}
}
int main() {
	scanf("%d%d%d", &N, &A, &B);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);

	for(int d = -1; d <= 1; d++) {
		solve1(D[1] + d, 0);
		solve1(D[N] + d, 1);
	}

	printf("%lld\n", ans);
	return 0;
}