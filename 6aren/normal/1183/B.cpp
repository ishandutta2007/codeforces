#include<bits/stdc++.h>

using namespace std;

int mx[105], mn[105];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		int mini = 1e9;
		for (int i = 1; i <= n; i++) {
			int u;
			cin >> u;
			mx[i] = u + k;
			mn[i] = u - k;
			mini = min(mini, mx[i]);
		}
		bool flag = 1;
		for (int i = 1; i <= n; i++) {
			if (mn[i] > mini) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			cout << -1 << endl;
		} else {
			cout << mini << endl;
		}
	}
	return 0;
}