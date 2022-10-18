#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int flag = 1, bal = 0;
        s = "#" + s;
        vector < int > cur;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '(') bal++;
            else if (s[i] == ')') bal--;
            else cur.push_back(i);
        }
        int cnt_open = 0, cnt_close = 0;
        if (bal >= 0) {
            cnt_open = ((int)cur.size() - bal) / 2;
            cnt_close = cnt_open + bal;
        } else {
            cnt_close = ((int)cur.size() + bal) / 2;
            cnt_open = cnt_close - bal;
        }
        int ok = 0;
        if (cnt_open > 0 && cnt_close > 0) {
            for (int i = 0; i < (int)cur.size(); i++) {
                if (i < cnt_open - 1) s[cur[i]] = '(';
                else if (i == cnt_open - 1) s[cur[i]] = ')';
                else if (i == cnt_open) s[cur[i]] = '(';
                else s[cur[i]] = ')';
            }
            int bal = 0;
            for (int i = 1; i <= n; i++) {
                if (s[i] == '(') bal++;
                else bal--;
                if (bal < 0) ok = 1;
            }
        } else ok = 1;
        if (ok) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}