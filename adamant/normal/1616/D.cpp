#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

const int MOD = 998244353;
const int inf = 1e16;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int p[n + 1];
    p[0] = 0;
    int px[n + 1];
    px[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int ans = 0;
    int last = -1;
    vector<pair<int, int>> st;
    // p[r] - x * r < p[l] - x * l
    for(int i = 0; i < n; i++) {
        p[i + 1] = p[i] + a[i];
        px[i + 1] = p[i + 1] - x * (i + 1);
        if(i > 0) {
            while(st.size() && st.back().first <= px[i - 1]) {
                st.pop_back();
            }
            st.push_back({px[i - 1], i - 1});
            auto t = upper_bound(st.rbegin(), st.rend(), make_pair(px[i + 1], n));
            if(t != st.rend() && t->second >= last) {
                ans++;
                last = i + 1;
            }
        }
    }
    cout << n - ans << "\n";
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