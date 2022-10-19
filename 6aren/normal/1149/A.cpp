#include<bits/stdc++.h>

using namespace std;

int n, cnt[3];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		cnt[u]++;
	}
	if (cnt[1] == 0) {
		for (int i = 1; i <= n; i++) {
			cout << "2 ";
		}
	} else if (cnt[2] == 0) {
		for (int i = 1; i <= n; i++) {
			cout << "1 ";
		}
	} else {
		cout << "2 1 ";
		cnt[2]--;
		cnt[1]--;
		while (cnt[2]--) {
			cout << "2 ";
		}
		while (cnt[1]--) {
			cout << "1 ";
		}
	}
	return 0;
}