#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int INF = 1e9;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector <int> a(6);
    for (int i = 0; i < 6; ++i) cin >> a[i];
    int n;
    cin >> n;
    vector <int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector <int> all;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            all.push_back(b[i] - a[j]);
        }
    }
    map <int, int> d;
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    for (int i = 0; i < all.size(); ++i) {
        d[all[i]] = i;
    }
    multiset<int> cur;
    vector <vector <int>> flex(all.size());
    vector <int> cha(n);
    for (int i = 0; i < n; ++i) {
        int maxx = 0;
        for (int j = 0; j < 6; ++j) {
            flex[d[b[i] - a[j]]].push_back(i);
            maxx = max(maxx, b[i] - a[j]);
        }
        cur.insert(maxx);
        cha[i] = maxx;
    }
    for (int i = 0; i < all.size(); ++i) {
        sort(flex[i].begin(), flex[i].end());
        flex[i].resize(unique(flex[i].begin(), flex[i].end()) - flex[i].begin());
    }
    int ans = INF;
    for (int i = (int)all.size() - 1; i >= 0; --i) {
        ans = min(ans, all[i] - *cur.begin());
        for (int j : flex[i]) {
            int maxx = -1;
            for (int k = 0; k < 6; ++k) {
                if (b[j] - a[k] < all[i]) {
                    maxx = max(maxx, b[j] - a[k]);
                }
            }
            if (maxx == -1) {
                cout << ans;
                return 0;
            }
            cur.erase(cur.find(cha[j]));
            cur.insert(maxx);
            cha[j] = maxx;
        }
    }
    cout << ans;
}