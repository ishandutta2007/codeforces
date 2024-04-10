#include<bits/stdc++.h>

using namespace std;

map < string, int > cnt;
map < string, int > good;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        cnt[s]++;
    }
    string ans = "";
    set < string > was;
    for (auto key : cnt) {
        if (was.find(key.first) != was.end()) continue;
        was.insert(key.first);
        string s = key.first;
        reverse(s.begin(), s.end());
        if (s == key.first) {
            for (int j = 0; j < key.second / 2; ++j) ans += key.first;
            good[s] = key.second % 2;
            continue;
        }
        was.insert(s);
        int f = 0;
        if (cnt.find(s) != cnt.end()) f = cnt[s];
        for (int j = 0; j < min(key.second, f); ++j) ans += key.first;
        good[s] = max(key.second, f) - min(key.second, f);
    }
    string add = "";
    for (auto key : good) {
        if (key.second >= 1) {
            string s = key.first;
            reverse(s.begin(), s.end());
            if (s == key.first) {
                if ((int)s.size() > (int)add.size()) add = s;
            }
        }
    }
    cout << 2 * (int)ans.size() + (int)add.size() << '\n';
    cout << ans;
    cout << add;
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}