#include<bits/stdc++.h>

using namespace std;

int const maxn = 3e5 + 5;
int a[maxn];
int b[maxn];
pair < int, int > where[maxn];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    vector < int > t = {n};
    set < int > used;
    for (int i = 0; i <= n; ++i) {
        used.insert(i);
    }
    int head = 0;
    while (head < (int)t.size()) {
        int v = t[head++];
        int l = v - a[v], r = v;
        auto it = used.lower_bound(l);
        vector < int > del;
        while (it != used.end() && (*it) <= r) {
            int val = (*it);
            int out = val + b[val];
            if (where[out].first == 0) {
                where[out] = {v, v - (r - val)};
                t.push_back(out);
            }
            del.push_back(val);
            it++;
        }
        for (auto key : del) used.erase(key);
    }
    if (where[0].first == 0) {
        cout << -1 << '\n';
        exit(0);
    }
    vector < int > ans = {};
    int now = 0;
    while (now != n) {
        ans.push_back(where[now].second);
        now = where[now].first;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto key : ans) cout << key << " ";
    return 0;
}