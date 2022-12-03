#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, zap;
    cin >> n >> zap;
    vector<int> a(n);
    vector<vector<int>> q(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        q[a[i]].push_back(i);
    }
    auto get = [&](int i, int l, int r) -> int {
        return lower_bound(q[i].begin(), q[i].end(), r + 1) - lower_bound(q[i].begin(), q[i].end(), l);
    };
    vector<int> cnt(n);
    while (zap--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int ans = 1;
        vector<int> b;
        for (int it = 0; it < 100; it++) {
            b.push_back(a[rnd() % (r - l + 1) + l]);
        }
        vector<int> q = {-1, -1, -1, -1};
        vector<int> z;
        for (int i : b) {
            if (cnt[i] == 0)
                z.push_back(i);
            cnt[i]++;
        }
        for (int i : z) {
            for (int j = 0; j < q.size(); j++) {
                if (q[j] == -1 || cnt[q[j]] < cnt[i]) {
                    for (int k = q.size() - 1; k > j; k--)
                        q[k] = q[k - 1];
                    q[j] = i;
                    break;
                }
            }
        }
        for (int i : b)
            cnt[i]--;
        for (int id : q)
        if (id != -1) {
            int x = get(id, l, r);
            int y = r - l + 1 - x;
            ans = max(ans, x - y);
        }
        cout << ans << '\n';
    }
}