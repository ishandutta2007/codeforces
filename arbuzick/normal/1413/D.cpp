#include <bits/stdc++.h>
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<char, int>> q(n*2);
    vector<pair<int, int>> q2;
    set<pair<int, int>> t;
    for (int i = 0; i < n*2; ++i) {
        cin >> q[i].f;
        if (q[i].f == '-')
            cin >> q[i].s, q2.pb({q[i].s, i});
        else
            t.insert({i, t.size()});
    }
    vector<int> ans(n);
    sort(all(q2));
    for (int i = 0; i < n; ++i) {
        if (t.begin()->f > q2[i].s) {
            cout << "NO";
            return 0;
        }
        auto it = t.lower_bound({q2[i].s, 0});
        it--;
        ans[it->s] = q2[i].f;
        t.erase(it);
    }
    set<int> now;
    int j = 0;
    for (int i = 0; i < n*2; ++i) {
        if (q[i].f == '+')
            now.insert(ans[j]), j++;
        else {
            if (*now.begin() != q[i].s) {
                cout << "NO";
                return 0;
            }
            now.erase(now.begin());
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    return 0;
}