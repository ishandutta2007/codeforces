#include<bits/stdc++.h>

using namespace std;

#define int long long
int mod = 1e9 + 7;

void solve() {
    int x, ans;
    cin >> x;
    string s;
    cin >> s;
    ans = (int)s.size();
    int sz = (int)s.size(), b = 0;
    string go = "";
    int lst;
    for (int i = 1; i <= x; ++i) {
        if (i == 1) {
            for (int j = 1; j < (int)s.size(); ++j) {
                go += s[j];
            }
            lst = s[0] - '0';
        }
        else {
            lst = go[i - 2] - '0';
        }
        b = sz - i;
        if (b < 0) b += mod;
        sz = i;
        int cnt = lst;
        sz += cnt * b;
        sz %= mod;
        int T = (int)go.size();
        if ((int)go.size() < x) {
            for (int pos = 1; pos < lst; ++pos) {
                for (int j = i - 1; j < T; ++j) {
                    go += go[j];
                }
            }
        }
        //cout << go << " " << sz << " " << lst << '\n';
    }
    cout << sz << '\n';
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}