#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

int N;
int x[MAXN];
ll y[MAXN];

void load() {
	scanf("%d", &N);
	N /= 2;
	for (int i = 0; i < N; i++)
		scanf("%d", x + i);
}

void solve() {
	int lst = 0;
	for (int i = 0; i < N; i++) {
		int p = 0, q = 0;
		for (int j = 1; j * j < x[i]; j++)
			if (!(x[i] % j)) {
				int k = x[i] / j;
				if ((j + k) % 2 || (k - j) / 2 <= lst)
					continue;
				p = j;
				q = k;
			}
			
		if (!p) {
			puts("No");
			return;
		}
		
		int b = (q - p) / 2;
		y[i] = (ll)b * b - (ll)lst * lst;
		lst = (p + q) / 2;
	}
	
	puts("Yes");
	for (int i = 0; i < N; i++)
		printf("%lld %d ", y[i], x[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}