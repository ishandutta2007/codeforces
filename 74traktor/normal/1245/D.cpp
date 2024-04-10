#include <bits/stdc++.h>

using namespace std;

#define int long long
pair < int, int > a[2005];
vector < pair < int, int > > g[2005];
int c[2005];
int k[2005];
int go[2005];
int lst[2005];
int used[2005];
int inf = 1e18;
map < int, int > aa;
set <pair < int, int > > outs;

main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) cin >> k[i];
    int ok = 0, ans = 0;
    vector < int > out1;
    vector < pair < int, int > >  out2;
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            g[i].push_back({j, (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second)) * (k[i] + k[j])});
        }
    }
    set < pair < int, int > > Q;
    for (int i = 1; i <= n; ++i) aa[i] = c[i], Q.insert({c[i], i});
    int sum = 0;
    while ((int)Q.size() > 0) {
        pair < int, int > cur = (*Q.begin());
        Q.erase(cur);
        sum += cur.first;
        if (cur.first == c[cur.second]) out1.push_back(cur.second);
        else out2.push_back({cur.second, lst[cur.second]});
        used[cur.second] = 1;
        for (auto key : g[cur.second]) {
            if (used[key.first]) continue;
            if (key.second < aa[key.first]) {
                Q.erase({aa[key.first], key.first});
                aa[key.first] = key.second;
                lst[key.first] = cur.second;
                Q.insert({aa[key.first], key.first});
            }
        }
    }
    cout << sum << '\n';
    cout << out1.size() << '\n';
    for (auto key : out1) cout << key << " ";
    cout << '\n';
    cout << out2.size() << '\n';
    for (auto key : out2) cout << key.first << " " << key.second << '\n';
    return 0;
}