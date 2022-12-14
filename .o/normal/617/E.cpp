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

const int N_ = 100500;
const int B = 300;
const int MAXV = 1<<21;

int N, M, K;
int A[N_];

vector<int> pos[MAXV + 10];

int count (int v, int l, int r) {
	if(v > MAXV) return 0;
	l = max(l, 0);
	r = min(r, N);
	if(l > r) return 0;

	int posl = -1, posr = -1;
	{
		int low = 0, high = (int)pos[v].size() - 1;
		while(low <= high) {
			int mid = (low + high) >> 1;
			if(pos[v][mid] >= l) {
				high = mid - 1;
				posl = mid;
			}else {
				low = mid + 1;
			}
		}
	}
	{
		int low = 0, high = (int)pos[v].size() - 1;
		while(low <= high) {
			int mid = (low + high) >> 1;
			if(pos[v][mid] <= r) {
				low = mid + 1;
				posr = mid;
			}else {
				high = mid - 1;
			}
		}
	}
	if(posl < 0) return 0;
	return posr - posl + 1;
}

ll pre[500][500];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	pos[0].push_back(0);
	for(int i = 1; i <= N; i++) {
		scanf("%d", A+i);
		A[i] ^= A[i-1];
		pos[A[i]].push_back(i);
	}

	for(int p = 0; p * B <= N; p++) {
		for(int q = p; q * B <= N; q++) {
			if(q > 0) pre[p][q] = pre[p][q-1];
			for(int i = q * B; i < (q+1) * B && i <= N; i++) {
				pre[p][q] += count(K ^ A[i], p * B - 1, i - 1);
			}
		}
	}

	while(M--) {
		int l, r; scanf("%d%d", &l, &r);
		ll ans = 0;

		if(r - l < 3 * B) {
			for(int i = l; i <= r; i++) {
				ans += count(K ^ A[i], l-1, i-1);
			}
		}else {
			int lb = 0;
			for(lb = l; lb % B != 0; lb++) {
				ans += count(K ^ A[lb-1], lb, r);
			}
			lb /= B;
			int rb = 0;
			for(rb = r; rb % B != B-1; rb--) {
				ans += count(K ^ A[rb], lb * B - 1, rb-1);
			}
			rb /= B;
			ans += pre[lb][rb];
		}
		printf("%lld\n", ans);

	}
    return 0;
}