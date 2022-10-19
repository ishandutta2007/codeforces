#include<bits/stdc++.h>

using namespace std;

int n, t;

int calc(int u, int v) {
	if (u >= t) return u;
	return (t - 1 - u) / v * v + u + v; 
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int mini = 1e9, index = 0;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		if (calc(u, v) < mini) {
			mini = calc(u, v);
			index = i;
		}
	}
	cout << index;
	return 0;
}