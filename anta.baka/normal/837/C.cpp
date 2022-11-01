#include <bits/stdc++.h>

using namespace std;

int n, a, b, x[100], y[100], ans;

bool can(int a1, int b1, int a2, int b2) {
	return (max(a1, a2) <= a && b1 + b2 <= b) || (a1 + a2 <= a && max(b1, b2) <= b);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(can(x[i], y[i], x[j], y[j]) || can(x[i], y[i], y[j], x[j]) || can(y[i], x[i], x[j], y[j]) || can(y[i], x[i], y[j], x[j]))
				ans = max(ans, x[i] * y[i] + x[j] * y[j]);
	cout << ans;
}