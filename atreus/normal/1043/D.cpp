#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 10;
const int block = 320;

int a[12][maxn], per[12][maxn], ptr[12], k[12];

int n, m;

bool nex (int x) {
	for (int j = 1; j <= m; j++) {
		if (k[j] != x)
			return 0;
	}
	return 1;
}

int main() {
	scanf ("%d%d", &n, &m); 
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf ("%d", &a[i][j]);
			per[i][a[i][j]] = j;
		}
	}
	ll ans = 0;
	int l = 1, r = 1;
	while (l <= n) {
		if (r == l) {
			for (int j = 1; j <= m; j++) {
				ptr[j] = per[j][a[1][l]] + 1;
				k[j] = a[j][ptr[j]];
			}
			r ++;
		}
		while (r <= n and nex (a[1][r])) {
			r ++;
			for (int j = 1; j <= m; j++) {
				ptr[j] ++;
				k[j] = a[j][ptr[j]];
			}
		}
		ans += 1ll * (r - l) * (r - l + 1) / 2;
		l = r;
	}
	printf ("%lld \n", ans);
}