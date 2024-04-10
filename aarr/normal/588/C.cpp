#include <iostream>
using namespace std;

const int N = 2000 * 1000 + 5;

int cnt[N];

int main() {
	ios :: sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (int i = 0; i < N; i++) {
		cnt[i + 1] += cnt[i] / 2;
		cnt[i] %= 2;
		if (cnt[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}