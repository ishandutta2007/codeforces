#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    set<int> s0, s1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && t[i] == '1') s0.insert(i);
        if (s[i] == '1' && t[i] == '0') s1.insert(i);
    }
    if (s0.size() != s1.size()) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    while (s0.size()) {
        ans++;
        int type = 0, ind = *s0.rbegin(), st = 0;
        if (*s1.rbegin() > *s0.rbegin()) type = 1, ind = *s1.rbegin(), st = 1;
        while (1) {
            if (type == 0) {
                if (st == 0) {
                    auto it = s1.lower_bound(ind);
                    if (it == s1.begin()) break;
                    s0.erase(ind);
                    it--;
                    ind = *it;
                    type = 1;
                } else {
                    s0.erase(ind);
                    auto it = s1.lower_bound(ind);
                    if (it == s1.begin()) break;
                    it--;
                    ind = *it;
                    type = 1;
                }
            }
            if (type == 1) {
                if (st == 0) {
                    s1.erase(ind);
                    auto it = s0.lower_bound(ind);
                    if (it == s0.begin()) break;
                    it--;
                    ind = *it;
                    type = 0;
                } else {
                    auto it = s0.lower_bound(ind);
                    if (it == s0.begin()) break;
                    s1.erase(ind);
                    it--;
                    ind = *it;
                    type = 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}