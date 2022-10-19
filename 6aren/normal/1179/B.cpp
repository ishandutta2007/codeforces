#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int n, m;
	cin >> n >> m;
	int l = 1, r = n;
	while (r > l) {
		for (int i = 1; i <= m; i++) {
			printf("%d %d\n", l, i);
			printf("%d %d\n", r, m + 1 - i);
		}
		l++;
		r--;
	}
	if (l == r) {
		int le = 1, ri = m;
		while (le < ri) {
			printf("%d %d \n", l, le);
			printf("%d %d \n", l, ri);
			le++;
			ri--;
		}
		if (le == ri) {
			printf("%d %d \n", l, le);
		}
	}
	return 0;
}