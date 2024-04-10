#include <bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string s1 = "[<({", s2 = "]>)}";
    int bal = 0;
    for (auto c : s) {
        for (int i = 0; i < 4; ++i) {
            if (s1[i] == c) bal++;
            if (s2[i] == c) bal--;
        }
        if (bal < 0) {
            cout << "Impossible" << '\n';
            return 0;
        }
    }
    if (bal != 0) {
        cout << "Impossible" << '\n';
        return 0;
    }
    int ans = 0;
    vector < int > st;
    for (auto c : s) {
        bool check = true;
        for (int i = 0; i < 4; ++i) {
            if (s1[i] == c) st.push_back(i), check = false;
        }
        if (check) {
            for (int i = 0; i < 4; ++i) {
                if (s2[i] == c) {
                    if (st.back() != i) ans++;
                }
            }
            st.pop_back();
        }
    }
    cout << ans << '\n';
    return 0;
}