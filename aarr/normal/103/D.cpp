#include <iostream>
#include <algorithm>
using namespace std;

const int N = 300 * 1000 + 5, SQ = 373;


int a[N];
long long dp[2 * N];
pair <pair <int, int>, int> t[N];
long long finans[N];
int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> t[i].first.second >> t[i].first.first;
		t[i].second = i;
	}
	sort(t + 1, t + q + 1);
	for (int i = 1; i <= q; i++) {
		int x = t[i].first.first, y = t[i].first.second;
		if (x < SQ) {
			if (x != t[i - 1].first.first) {
				for (int j = n; j > 0; j--) {
					dp[j] = dp[j + x] + a[j];
				}
			}
			finans[t[i].second] = dp[y];
		}
		else {
			long long ans = 0;
			for (int j = y; j <= n; j += x) {
				ans += a[j];
			}
			finans[t[i].second] = ans;
		}
		
	}
	for (int i = 1; i <= q; i++) {
		cout << finans[i] << '\n';
	}
	return 0;
}