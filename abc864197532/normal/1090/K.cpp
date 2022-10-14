#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
int myhash(string s) {
    ll hs = 0;
    for (int i = 0; i < s.size(); ++i) {
        hs *= 203;
        hs += s[i];
        hs %= mod;
    }
    return hs;
}
int myhash2(string s) {
    ll hs = 0;
    for (int i = 0; i < s.size(); ++i) {
        hs *= 203;
        hs += s[i];
        hs %= mod2;
    }
    return hs;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    map<pp, int> mp;
    vector<vector<int>> ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        sort(t.begin(), t.end()), t.resize(unique(t.begin(), t.end()) - t.begin());
        while (s.length() && count(t.begin(), t.end(), s.back())) s.pop_back();
        pp tmp(make_pair(myhash(s), myhash(t)), make_pair(myhash2(s), myhash2(t)));
        if (!mp.count(tmp))
            mp[tmp] = ans.size(), ans.emplace_back();
        ans[mp[tmp]].push_back(i);
    }
    cout << ans.size();
    for (auto i : ans) {
        cout << '\n' << i.size();
        for (int j : i) cout << ' ' << j + 1;
    }
}