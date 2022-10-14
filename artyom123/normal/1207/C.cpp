#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define int long long

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
    	long long n, a, b;
    	cin >> n >> a >> b;
    	string s;
    	cin >> s;
    	vector <pair<long long, int>> l;
    	long long ans = 0;
    	for (auto &c : s) {
    		if (l.size() == 0 || l.back().second != c - '0') {
    			l.pb({1, c - '0'});
    		} else {
    			l.back().first++;
    		}
    	}
    	for (auto &c : l) {
    		if (c.second == 1) {
    			ans += (c.first + 1) * 2 * b;
    			ans += c.first * a;
    		}
    	}
    	if (l.size() == 1) {
    		cout << b * (n + 1) + a * n << "\n";
    		continue;
    	}
    	ans += l[0].first * b + 2 * a + (l[0].first - 1) * a;
    	ans += l.back().first * b + 2 * a + (l.back().first - 1) * a;
    	for (int i = 1; i + 1 < l.size(); i++) {
    		if (l[i].second == 1) {
    			continue;
    		}
    		ans += min((l[i].first - 1) * 2 * b + l[i].first * a, (l[i].first + 2) * a + (l[i].first - 1) * b);
    	}
    	cout << ans << "\n";
    }

    return 0;
}