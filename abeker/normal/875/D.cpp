#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int LOG = 18;

int N;
int a[MAXN];
int sparse[MAXN][LOG];
int exp[MAXN];
map <int, int> last;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

bool subset(int x, int y) {
	return (y & x) == x;
}

int get(int lo, int hi) {
	int e = exp[hi - lo];
	return sparse[lo][e] | sparse[hi - (1 << e)][e];
}

int find_left(int x) {
	int lo = last[a[x]] + 1, hi = x;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (subset(get(mid, x), a[x]))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int find_right(int x) {
	int lo = x + 1, hi = N;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (subset(get(x + 1, mid + 1), a[x]))
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

ll solve() {
	for (int i = 2; i <= N; i++)
		exp[i] = exp[i / 2] + 1;
	
	for (int i = 0; i < N; i++)
		sparse[i][0] = a[i];
	
	for (int j = 1; j < LOG; j++)
		for (int i = 0; i < N; i++)
			sparse[i][j] = i + (1 << j - 1) < N ? (sparse[i][j - 1] | sparse[i + (1 << j - 1)][j - 1]) : 0;
	
	for (int i = 0; i < N; i++)
		last[a[i]] = -1;
		
	ll sol = (ll)N * (N + 1) / 2;
	for (int i = 0; i < N; i++) {
		sol -= (ll)(i - find_left(i) + 1) * (find_right(i) - i);	
	 	last[a[i]] = i;
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}