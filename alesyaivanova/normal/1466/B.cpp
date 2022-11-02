#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
int cnt[maxn];
int cnt1[maxn];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= 2 * n + 1; i++) {
        cnt[i] = 0;
        cnt1[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n + 1; i++) {
        if (cnt[i]) {
            if (cnt1[i]) {
                cnt1[i + 1] += cnt[i];
                cnt[i] = 0;
            } else if (cnt[i] >= 2) {
                cnt1[i + 1] += cnt[i] - 1;
                cnt[i] = 1;
            }
        }

        if (cnt[i] || cnt1[i])
            ans++;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}