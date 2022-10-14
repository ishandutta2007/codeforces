#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define int long long
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 1;

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, k, d;
		cin >> n >> k >> d;
		vector <int> a(n);
		for (auto &c : a) {
			cin >> c;
		}
		set <int> s;
		map <int, int> cnt;
		for (int i = 0; i < d; i++) {
			s.insert(a[i]);
			cnt[a[i]]++;
		}
		int ans = s.size();
		for (int i = d; i < n; i++) {
			s.insert(a[i]);
			cnt[a[i]]++;
			if (cnt[a[i - d]] == 1) {
				s.erase(a[i - d]);
			}
			cnt[a[i - d]]--;
			ans = min(ans, (long long)s.size());
		}
		cout << ans << "\n";
	}
	return 0;
}