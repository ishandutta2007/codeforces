#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &e : a) cin >> e;
    vector<vector<int>> segs;
    vector<int> cur = {a[0]};
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            segs.push_back(cur);
            cur.clear();
            cur.push_back(a[i]);
        } else cur.push_back(a[i]);
    }
    segs.push_back(cur);
    int ans = 0;
    for (int i = 0; i < segs.size(); i++) {
        while (segs[i].size() > 2) segs[i].pop_back();
    }

    int u, v;
    u = v = -1;
    for (int i = 0; i < segs.size(); i++) {
        auto seg = segs[i];
        if (seg.size() == 2) {
            int x = seg[0];
            ans += (x != u);
            ans += (x != v);
            u = v = x;
        } else {
            int x = seg[0];
            int nx = -1;
            if (i + 1 < segs.size()) nx = segs[i + 1][0];
            if (u == nx) {
                ans++;
                u = x;
            } else if (v == nx) {
                ans++;
                v = x;
            } else {
                if (u != x) {
                    ans++;
                    u = x;
                } else {
                    ans++;
                    v = x;
                }
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}