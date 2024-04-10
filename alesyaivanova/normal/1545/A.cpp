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

const int maxn = 1e5 + 9;
int n;

void solve() {
    cin >> n;
    map<int, pair<int, int> > cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0)
            cnt[x].first++;
        else
            cnt[x].second++;
    }
    int m = 0;
    for (auto j : cnt) {
        int cnt0 = j.ss.ff;
        int cnt1 = j.ss.ss;
        if (abs(cnt0 - cnt1) >= 2) {
            cout << "NO\n";
            return;
        }
        if ((m % 2 == 0 && cnt1 > cnt0) || (m % 2 == 1 && cnt0 > cnt1)) {
            cout << "NO\n";
            return;
        }
        m += cnt0 + cnt1;
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}