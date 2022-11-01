#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int cnt[1005];

int main() {
	int n, m;
	cin >> n >> m;
	int ans = m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1; i <= n; i++) {
		ans = min(ans, cnt[i]);
	}
	cout << ans;
}