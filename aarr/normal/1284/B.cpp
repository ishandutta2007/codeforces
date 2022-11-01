#include <bits/stdc++.h>
using namespace std;


const int N = 100 * 1000 + 5, inf = 1000 * 1000 + 5;

int maxi[N], mini[N];
int cnt[inf];
vector <int> a[N];
bool b[N];
int main() {
	ios :: sync_with_stdio(false);
	int n, s = 0;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mini[i] = inf;
		for (int j = 0; j < x; j++) {
			int y;
			cin >> y;
			a[i].push_back(y);
			if (mini[i] < y) {
				b[i] = true;
			}
			maxi[i] = max(maxi[i], y);
			mini[i] = min(mini[i], y);
		}
		if (!b[i])
			cnt[mini[i]]++;
		else {
			s++;
		}
	}
	ans += 2ll * s * n - 1ll * s * s;
	for (int i = 1; i < inf; i++) {
		cnt[i] += cnt[i - 1];
	}
	for (int i = 0; i < n; i++) {
		if (maxi[i] != 0 && !b[i])
			ans += cnt[maxi[i] - 1];
	} 
	cout << ans << endl;
	return 0;
}