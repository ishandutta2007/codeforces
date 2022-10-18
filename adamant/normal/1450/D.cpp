#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int maxn = 2e5 + 42;

void solve() {
    int n;
    cin >> n;
    deque<pair<int, int>> a(n);
    set<int> b;
    set<pair<int, int>> inside;
    for(int i = 0; i < n; i++) {
        a[i].first = i;
        cin >> a[i].second;
        a[i].second--;
        b.insert(a[i].second);
        inside.insert({a[i].second, a[i].first});
    }
    string ans(n, '0');
    ans[0] += b.size() == n;
    for(int i = 0; i < n - 1; i++) {
        if(inside.begin()->first == i) {
            ans[n - i - 1] = '1';
        }
        if(a.front().second == i) {
            inside.erase({a.front().second, a.front().first});
            a.pop_front();
        } else if(a.back().second == i) {
            inside.erase({a.back().second, a.back().first});
            a.pop_back();
        } else {
            break;
        }
    }
    cout << ans << "\n";
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