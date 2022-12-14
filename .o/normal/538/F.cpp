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

const int N_ = 200500;
int N, A[N_];
map<int, int> mp; int X;
vector<int> pos[N_];

struct query {
	int l, r, k;
	query (int l = 0, int r = 0, int k = 0): 
		l(l), r(r), k(k) { } 
};

vector<query> queries[N_];

int tree[N_];

void upd (int x, int d) {
	while(x <= N) {
		tree[x] += d;
		x += x & -x;
	}
}

ll ans[N_];

int get (int x) {
	int ret = 0;
	while(x > 0) {
		ret += tree[x];
		x -= x & -x;
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", A+i);
		mp[A[i]] = -1;
	}
	for(auto &it : mp) it.second = ++X;
	for(int i = 1; i <= N; i++) {
		A[i] = mp[A[i]];
		pos[A[i]].push_back(i);
	}

	for(int k = 1; k <= N-1; k++) {
		for(int i = 1; k * (i - 1) + 2 <= N; i++) {
			queries[A[i]].push_back(query(k * (i-1) + 2, min(k * i + 1, N), k));
		}
	}

	for(int x = 1; x <= X; x++) {
		for(auto q : queries[x]) ans[q.k] += get(q.r) - get(q.l - 1);
		for(auto i : pos[x]) upd(i, +1);
	}

	for(int k = 1; k <= N-1; k++) {
		printf("%lld%c", ans[k], (k == N-1) ? '\n' : ' ');
	}


	return 0;
}