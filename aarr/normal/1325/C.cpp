#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;
int x[N];
int y[N];
pair <int, int> a[N];
int deg[N];
int ans[N];

int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x[i] >> y[i];
		deg[x[i]]++, deg[y[i]]++;
	}
	for (int i = 1; i < n; i++) {
		a[i] = {min(deg[x[i]], deg[y[i]]), i};
	}
	sort(a + 1, a + n);
	for (int i = 1; i < n; i++) {
		ans[a[i].second] = i - 1;
	}
	for (int i = 1; i < n; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}