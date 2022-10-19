#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

void solve() {
    string s;
    cin >> s;
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            cnt = 1;
            continue;
        }
        if (s[i] != s[i - 1]) {
            if (s[i - 1] == '1') v.pb(cnt);
            cnt = 1;
        } else cnt++;
    }
    if (s.back() == '1') v.pb(cnt);
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0; i < v.size(); i += 2) {
        ans += v[i];
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) solve();
    return 0;
}