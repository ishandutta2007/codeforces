#include <bits/stdc++.h>
using namespace std;

bool flag[11], bo = 0;
int ans = 10;

int main() {
	
	int n, m, Mina = 10, Minb = 10;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		Mina = min(Mina, x);
		flag[x] = 1;
	}
	for (int i = 1; i <= m; ++i) {
		int x;
		scanf("%d", &x);
		if (flag[x]) {
			bo = 1;
			ans = min(x, ans);
		}
		Minb = min(Minb, x);
	}
	if (bo) cout << ans;
	else cout << min(Mina, Minb) << max(Mina, Minb) << endl;
	return 0;
	
}