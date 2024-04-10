#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n;
    vector < pair < int, int > > a;
    for (int i = 1; i <= n; ++i) {
        cin >> d;
        a.push_back({d, i});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector < pair < int, int > > output;
    for (int i = 1; i < n; ++i) {
        output.push_back({a[i - 1].second * 2 - 1, a[i].second * 2 - 1});
    }
    vector < int > b;
    for (int i = 0; i < n; ++i) b.push_back(a[i].second * 2 - 1);
    for (int i = 0; i < n; ++i) {
        int nxt = i + a[i].first - 1;
        //cout << i << " " << nxt << " " << b[nxt] << '\n';
        output.push_back({a[i].second * 2, b[nxt]});
        if (nxt == (int)b.size() - 1) {
            b.push_back(a[i].second * 2);
        }
    }
    for (auto key : output) cout << key.first << " " << key.second << '\n';
    return 0;
}