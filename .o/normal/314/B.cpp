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

const int N_ = 10005;

int B, D;
char A[N_], C[N_];
int AN, CN;
int Table[N_], Table_b[N_][5];
int res;

int main() {
	int i, j, k;

	scanf("%d%d%s%s", &B, &D, A, C);
	AN = strlen(A);
	CN = strlen(C);

	for(i = 0; i < CN; i++) {
		int &t = Table[i];
		for(j = 0, t = i; j < AN; j++) if(A[j] == C[t%CN]) ++t;
		if(t == i) return 0 & puts("0");
	}

	k = 0;
	for(i = 0; i < B; i++) {
		int *tb = Table_b[k];
		if(tb[2] != 1) {
			tb[0] = i; tb[1] = res; tb[2] = 1;
			k = Table[k]; res += k / CN; k %= CN;
		}else {
			int v = (B - i) / (i - tb[0]);
			res += v * (res - tb[1]);
			i += v * (i - tb[0]);
			break;
		}
	}

	while(i < B) {
		k = Table[k]; res += k / CN; k %= CN;
		++i;
	}

	printf("%d\n", res / D);
	return 0;
}