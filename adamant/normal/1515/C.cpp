#include <bits/stdc++.h>

using namespace std;

bool is_sqr(int n) {
    int k = sqrt(n);
    return k * k == n;
}

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    cout << "YES\n";
    set<pair<int, int>> que;
    for(int i = 0; i < m; i++) {
        que.insert({0, i});
    }
    for(int i = 0; i < n; i++) {
        int h;
        cin >> h;
        int j = begin(que)->second;
        cout << j + 1 << ' ';
        int s = begin(que)->first + h;
        que.erase(begin(que));
        que.insert({s, j});
    }
    cout << "\n";

}

signed main() {
    //freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}