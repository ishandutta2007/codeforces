#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int n = s.size();
    map<char, int> count;
    for (auto ch : s) {
        count[ch]++;
    }
    if (count['A'] != a + c + d) {
        cout << "NO\n";
        return;
    }
    set<pair<int, pair<int, int>>> st1;
    multiset<int> st2;
    for (int i = 0; i + 1 < n; ++i) {
        int pos = i;
        while (pos + 1 < n && s[pos + 1] != s[pos]) {
            pos++;
        }
        if (pos == i) {
            continue;
        }
        if (s[pos] != s[i]) {
            st1.insert(make_pair((pos - i + 1) / 2 - 1, make_pair(i, pos + 1)));
        } else {
            st2.insert((pos - i) / 2);
        }
        i = pos;
    }
    while (!st1.empty()) {
        auto p = *st1.begin();
        st1.erase(st1.begin());
        if (s[p.second.first] == 'A') {
            int val = min(c, p.first + 1);
            c -= val;
            p.first -= val;
            if (p.first > 0) {
                d = max(0, d - p.first);
            }
        } else {
            int val = min(d, p.first + 1);
            d -= val;
            p.first -= val;
            if (p.first > 0) {
                c = max(0, c - p.first);
            }
        }
    }
    while (!st2.empty()) {
        int val = *st2.begin();
        st2.erase(st2.begin());
        int v = min(c, val);
        c -= v;
        val -= v;
        d = max(0, d - val);
    }
    if (c > 0 || d > 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}