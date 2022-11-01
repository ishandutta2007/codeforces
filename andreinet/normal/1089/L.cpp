#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n);
    vector<int> cnt(k, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].second;
        a[i].second--;
        cnt[a[i].second]++;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
    }
    int blank = 0;
    for (int i = 0; i < k; ++i) {
        blank += (cnt[i] == 0);
    }
    sort(a.begin(), a.end());
    int64_t ans = 0;
    for (auto& p: a) {
        if (blank == 0) {
            break;
        }
        if (cnt[p.second] > 1) {
            cnt[p.second]--;
            ans += p.first;
            blank--;
        }
    }
    cout << ans << '\n';
}