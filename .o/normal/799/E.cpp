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
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MOD = (int)1e9 + 7;

class modint {
  int v;
public:
  modint (): v(0) { }
  modint (ll v): v((v + MOD) % MOD) { }

  bool operator== (modint x) { return v == x.v; }
  bool operator!= (modint x) { return v != x.v; }

  modint operator+ (modint x) { return v + x.v; }
  modint operator- (modint x) { return v - x.v; }
  modint operator* (modint x) { return (ll)v * x.v; }

  modint& operator+= (const modint x) { return *this = (*this + x); }
  modint& operator-= (const modint x) { return *this = (*this - x); }
  modint& operator*= (const modint x) { return *this = (*this * x); }

  int operator* () { return v; }
};

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 200500;

int N, M, K;
int C[N_];
int L[N_];
vector<int> P[4];
vector<ll> S[4];

ll ans;

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &C[i]);
	}
	for(int r = 0; r < 2; r++) {
		int a; scanf("%d", &a);
		for(int i = 0; i < a; i++) {
			int x; scanf("%d", &x);
			L[x] |= 1<<r;
		}
	}
	ans = ll(1e18);

	for(int i = 1; i <= N; i++) {
		P[L[i]].push_back(C[i]);
	}

	for(int mask = 0; mask < 4; mask++) {
		sort(P[mask].begin(), P[mask].end());
		long long sum = 0;
		for(int p : P[mask]) {
			sum += p;
			S[mask].push_back(sum);
		}
	}

	for(int t = 0; t <= K; t++) {
		if(t <= S[3].size() && K - t <= S[1].size() && K - t <= S[2].size()) {
			long long ret = 0;
			if(K-t-1 >= 0) ret += S[1][K-t-1];
			if(K-t-1 >= 0) ret += S[2][K-t-1];
			if(t-1 >= 0) ret += S[3][t-1];

			int u = t + K-t + K-t;
			if(u > M) continue;
			if(u < M) {
				int low = 0, high = int(1e9), pos = -1;
				int penalty[] = {0, K-t, K-t, t};
				while(low <= high) {
					int mid = (low + high) >> 1;
					int cnt = 0;
					for(int mask = 0; mask < 4; mask++) {
						int p = upper_bound(P[mask].begin(), P[mask].end(), mid) - P[mask].begin();
						cnt += max(p - penalty[mask], 0);
					}
					if(cnt >= M - u) {
						pos = mid;
						high = mid-1;
					}else {
						low = mid+1;
					}
				}
				if(pos == -1) continue;
				for(int mask = 0; mask < 4; mask++) {
					int p = upper_bound(P[mask].begin(), P[mask].end(), pos) - P[mask].begin();
					if(p > penalty[mask]) {
						u += p - penalty[mask];
						if(p-1 >= 0) ret += S[mask][p-1];
						if(penalty[mask] - 1 >= 0) ret -= S[mask][penalty[mask] - 1];
					}
				}
				if(u > M) {
					ret -= (u - M) * pos;
					u = M;
				}
				assert(u == M);
			}

			if(u == M) {
				ans = min(ans, ret);
			}
		}
	}

	if(ans == ll(1e18)) ans = -1;
	printf("%lld\n", ans);
  return 0;
}