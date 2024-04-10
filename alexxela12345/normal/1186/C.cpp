#include <bits/stdc++.h>
using namespace std;

//#define int long long
//#define endl "\n"

typedef long long ll;

//01100010
//00110

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int cnt_cur = 0;
    for (int i = 0; i < t.size(); i++) {
        if (s[i] != t[i]) {
            cnt_cur++;
        }
    }
    vector<int> changes(s.size() - 1);
    for (int i = 0; i < changes.size(); i++) {
        if (s[i] != s[i + 1]) {
            changes[i] = 1;
        }
    }
    vector<int> pref_sum(changes.size() + 1);
    for (int i = 1; i <= changes.size(); i++) {
        pref_sum[i] = pref_sum[i - 1] + changes[i - 1];
    }
    int cur_st = 0;
    int ans = 0;
    while (true) {
        if (cnt_cur % 2 == 0) {
            ans++;
        }
        if (cur_st + t.size() == s.size()) {
            break;
        }
        cnt_cur += pref_sum[cur_st + t.size()] - pref_sum[cur_st];
        cur_st++;
    }
    cout << ans << endl;
    return 0;
}