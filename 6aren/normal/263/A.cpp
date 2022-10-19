#include<bits/stdc++.h>

using namespace std;

int ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			int u;
			cin >> u;
			if (u == 1) ans = abs(i - 3) + abs(j - 3);
		}
	}
	cout << ans;
	return 0;
}