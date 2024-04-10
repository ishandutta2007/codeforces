#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 1000005;

int N, K;
int f[MAXN];

void update(int x) {
	for (x++; x < MAXN; x += x & -x)
		f[x]++;
}

int get(int x) {
	int res = 0;
	for (x++; x; x -= x & -x)
		res += f[x];
	return res;
}

int query(int lo, int hi) {
	if (lo < hi) 
		return get(hi - 1) - get(lo);
	return get(N - 1) - get(lo) + get(hi - 1);
}

int main() {
	scanf("%d%d", &N, &K);
	if (K > N - K)
		K = N - K;
		
	ll curr = 1;
	int pos = 0;
	for (int i = 0; i < N; i++) {
		int nxt = (pos + K) % N;
		curr += query(pos, nxt) + 1;
		printf("%lld ", curr);
		update(pos);
		update(nxt);
		pos = nxt;
	}
	puts("");
	
	return 0;
}