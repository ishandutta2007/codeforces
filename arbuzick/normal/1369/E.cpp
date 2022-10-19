#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> w(n), cnt(n);
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    vector<pair<int, int>> x(m);
    vector<set<int>> a(n);
    for (int i = 0; i < m; ++i) {
        cin >> x[i].first >> x[i].second;
        x[i].first--;
        x[i].second--;
        cnt[x[i].first]++;
        cnt[x[i].second]++;
        a[x[i].first].insert(i);
        a[x[i].second].insert(i);
    }
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i)
        s.insert({ cnt[i] - w[i], i });
    vector<int> ans;
    while (!s.empty()) {
        pair<int, int> p = *s.begin();
        if (p.first > 0) {
            cout << "DEAD\n";
            return 0;
        }
        s.erase(p);
        for (int f : a[p.second]) {
            ans.push_back(f + 1);
            if (x[f].first != p.second) {
                a[x[f].first].erase(f);
                s.erase({ cnt[x[f].first] - w[x[f].first], x[f].first });
                cnt[x[f].first]--;
                s.insert({ cnt[x[f].first] - w[x[f].first], x[f].first });
            }
            else {
                a[x[f].second].erase(f);
                s.erase({ cnt[x[f].second] - w[x[f].second], x[f].second });
                cnt[x[f].second]--;
                s.insert({ cnt[x[f].second] - w[x[f].second], x[f].second });
            }
        }
    }
    cout << "ALIVE\n";
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < m; ++i)
        cout << ans[i] << ' ';
    return 0;
}