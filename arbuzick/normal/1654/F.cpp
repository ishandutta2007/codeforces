#include <bits/stdc++.h>

using namespace std;

vector<int> get(vector<int> nw) {
    if (nw.size() == 1) {
        return nw;
    }
    vector<pair<int, int>> b;
    for (int i = 0; i < (int) nw.size(); i += 2) {
        b.emplace_back(nw[i], nw[i + 1]);
        b.emplace_back(nw[i + 1], nw[i]);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    vector<int> nw1, nw2;
    for (int i = 0; i < (int) nw.size(); i += 2) {
        nw1.push_back(lower_bound(b.begin(), b.end(), make_pair(nw[i], nw[i + 1])) - b.begin());
        nw2.push_back(lower_bound(b.begin(), b.end(), make_pair(nw[i + 1], nw[i])) - b.begin());
    }
    nw1 = get(nw1);
    nw2 = get(nw2);
    for (int i = 0; i < (int) nw1.size(); ++i) {
        if (nw2[i] < nw1[i]) {
            nw1 = nw2;
            break;
        } else if (nw1[i] < nw2[i]) {
            break;
        }
    }
    for (int i = 0; i < (int) nw1.size(); ++i) {
        nw[i * 2] = b[nw1[i]].first;
        nw[i * 2 + 1] = b[nw1[i]].second;
    }
    return nw;
}

void solve() {
    int n;
    cin >> n;
    n = (1 << n);
    string s;
    cin >> s;
    vector<int> nw(n);
    for (int i = 0; i < n; ++i) {
        nw[i] = s[i] - 'a';
    }
    nw = get(nw);
    for (int i = 0; i < n; ++i) {
        cout << char('a' + nw[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}