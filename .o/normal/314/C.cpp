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

inline int getint() {
	int n; scanf("%d", &n);
	return n;
}

inline ll getll() {
	ll n; scanf("%I64d", &n);
	return n;
}

const int N_ = 100005;
const int M_ = 1000005;
const ll MOD = (ll)(1e9)+7;
const int LEAF = (1<<20)-1;

int N, A[N_];
ll Table[N_];
int last[M_];
ll Tree[M_ ]; 
int Mark[M_ ], TIME;
ll res = 0;


ll get (int x) {
	ll ret = 0;
	while(x > 0) {
		ret = (ret + Tree[x]) % MOD;
		x -= x & -x;
	}
	return ret;
}

void update (int x, ll val) {
	val %= MOD;
	while(x < M_) {
		Tree[x] = (Tree[x] + val) % MOD;
		x += x & -x;
	}
}

ll MD (ll a){ return (a+MOD*100000)%MOD; }
ll MUL (ll a, ll b){ return (MD(a)*MD(b))%MOD; }
ll PL (ll a, ll b) { return (MD(a)+MD(b))%MOD; }

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", A+i);

	int mx = 0;
	for(i = 1; i <= N; i++) {
		++TIME;

		int x = 0;
		Table[i] = PL( MUL(get(A[i]), A[i]), -last[A[i]]+A[i]);
		res = (res + Table[i]) % MOD;
		update(A[i], Table[i]);
		last[A[i]] = PL(last[A[i]], Table[i]);
	}

	printf("%I64d\n", res % MOD);

	return 0;
}