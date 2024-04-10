#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, B = 300;
int n, m, a[N], f[B][N];
int main() {
	for(int i = (cin >> n, 1); i <= n; i++) cin >> a[i];
	for(int k = 1; k < B; k++) for(int p = n; p; p--)
		f[k][p] = p + a[p] + k > n ? 1 : f[k][p + a[p] + k] + 1;
	for(int i = (cin >> m, 1); i <= m; i++) {
		int p, k, ans = 0; cin >> p >> k;
		if(k >= B) while(p <= n) ans++, p += a[p] + k;
		else ans = f[k][p];
		cout << ans << "\n";
	}
	return 0;
}