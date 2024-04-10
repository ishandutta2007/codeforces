#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

using ll = long long;

const int MOD = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1)
            (res *= a) %= MOD;
        p >>= 1;
        (a *= a) %= MOD;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> pos(26);
    for (int i = 0; i < s.length(); i++)
        pos[s[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; i++)
        reverse(pos[i].begin(), pos[i].end());
    for (int i = 0; i + 1 < s.length(); i++) {
        int c = s[i] - 'a';
        if (pos[c].size() < 2)
            break;
        if (pos[c].back() != i)
            continue;
        pos[c].pop_back();
        // pos[c].pop_back();
    }
    vector<pair<int, char>> ans;
    for (int i = 0; i < 26; i++)
        for (int j : pos[i])
            ans.emplace_back(j, char(i + 'a'));
    sort(ans.begin(), ans.end());
    for (auto [i, c] : ans)
        cout << c;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}