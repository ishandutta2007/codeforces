#include <bits/stdc++.h>

using namespace std;

bool is_sqr(int n) {
    int k = sqrt(n);
    return k * k == n;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    int c[n];
    int cnt[n][2];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        cnt[c[i] - 1][i >= l]++;
    }
    int ans = 0;
    int T[2] = {l, r};
    int z = T[1] > T[0];
    int mx = 0;
    for(int i = 0; i < n; i++) {
        if(cnt[i][z] > cnt[i][!z]) {
            int k = min(cnt[i][z] - cnt[i][!z], T[z] - T[!z]) / 2;
            cnt[i][z] -= k;
            cnt[i][!z] += k;
            T[z] -= k;
            T[!z] += k;
            ans += k;
        }
        int t = min(cnt[i][z], cnt[i][!z]);
        cnt[i][0] -= t;
        cnt[i][1] -= t;
        T[0] -= t;
        T[1] -= t;
        mx = max({mx, cnt[i][0], cnt[i][1]});
        //cout << cnt[i][0] << ' ' << cnt[i][1] << ' ' << T[0] << ' ' << T[1] << endl;
    }
    // cnt[i][0] = 0 or cnt[i][1] = 0, T[0] == T[1]
    cout << ans + (T[z] - T[!z]) / 2 + (T[0] + T[1]) / 2 << "\n";
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