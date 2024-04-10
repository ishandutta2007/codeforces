#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define fpos alfla

const int maxn = 2e5 + 42;

vector<int> divs[maxn];
int cnt[maxn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 1; i < maxn; i++) {
		for(int j = i; j < maxn; j += i) {
			divs[i].push_back(j);
		}
	}
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	int ans = 0;
	for(int i = maxn - 1; i > 0; i--) {
		if(cnt[i]) {
			if(i < maxn - 1) {
				cnt[i] += cnt[i + 1];
			}
			int cur = 0;
			for(int j = i; j < maxn; j += i) {
				cur += j * (cnt[j] - (j + i >= maxn ? 0 : cnt[j + i]));
			}
			ans = max(ans, cur);
		} else {
			if(i < maxn - 1) {
				cnt[i] += cnt[i + 1];
			}
		}
	}
	cout << ans << endl;
	return 0;
}