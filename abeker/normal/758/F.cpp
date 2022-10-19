#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 10000005;

int N, L, R;
int p[MAXN];
vector <pii> all;

void load() {
	scanf("%d%d%d", &N, &L, &R);
}

void factor(int x) {
	int prod = 1, num = 0;
	while (x > 1) {
		int tmp = p[x], e = 0;
		for (; !(x % tmp); x /= tmp)
			e++;
		e %= N;
		if (e) {
			prod *= tmp;
			num = N * num + e;
		}
	}		
	all.push_back({prod, num});
}

ll choose(int x) {
	return (ll)x * (x - 1);
}

ll solve() {
	if (N == 1)
		return R - L + 1;
	N--;
	
	for (int i = 2; i < MAXN; i++) 
		if (!p[i])
			for (int j = i; j < MAXN; j += i)
				if (!p[j])
					p[j] = i;
	
	for (int i = L; i <= R; i++) 
		factor(i);
	
	sort(all.begin(), all.end());
	
	ll sol = 0;
	int cnt = 0;
	for (int i = 0; i < all.size(); i++) {
		if (i && all[i] != all[i - 1]) {
			sol += choose(cnt);
			cnt = 0;
		}
		cnt++;
	}
	sol += choose(cnt);
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}