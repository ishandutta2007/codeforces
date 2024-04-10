#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int sochan = 0;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		if (u % 2 == 0) sochan++;
	}
	cout << min(sochan, n - sochan);
	return 0;
}