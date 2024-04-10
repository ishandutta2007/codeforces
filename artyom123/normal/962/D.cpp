#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define int long long

void print(map<int, set<int>> &a) {
    vector<pair<int, int>> ans;
    for (auto &c : a) {
        for (auto &l : c.se) {
            ans.pb(l, c.fi);
        }
    }
    sort(all(ans));
    cout << ans.size() << "\n";
    for (auto &c : ans) {
        cout << c.se << " ";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, set<int>> gist;
    set<int> cur;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        gist[a[i]].insert(i);
        if (gist[a[i]].size() == 2) cur.insert(a[i]);
    }
    while (cur.size()) {
        int x = *cur.begin();
        if (gist[x].size() <= 3) cur.erase(cur.begin());
        gist[x].erase(gist[x].begin());
        int pos = *gist[x].begin();
        gist[x].erase(gist[x].begin());
        gist[2 * x].insert(pos);
        if (gist[2 * x].size() == 2) {
            cur.insert(2 * x);
        }
    }
    print(gist);
    return 0;
}