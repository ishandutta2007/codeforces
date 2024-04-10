#include <bits/stdc++.h>

using namespace std;

const int N = 1;

int n, prex, prey, curx, cury;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int ans = 1;
	prex = 0;
	prey = 0;
	for (int i = 1; i <= n; i++) {
		cin >> curx >> cury;
		ans += max(0, min(curx, cury) - max(prex, prey) + 1);
		if (prex == prey) {
			ans--;
		}
		prex = curx; prey = cury;
	}
	cout << ans;
	return 0;
}