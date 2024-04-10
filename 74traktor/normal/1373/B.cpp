#include<bits/stdc++.h>

using namespace std;

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        while (1) {
            int flag = 0;
            for (int i = 0; i < (int)s.size() - 1; ++i) {
                if (s[i] != s[i + 1]) {
                    flag = 1;
                    string new_s;
                    for (int j = 0; j < (int)s.size(); ++j) if (i != j && i + 1 != j) new_s += s[j];
                    s = new_s;
                    break;
                }
            }
            if (flag) cnt++;
            else break;
        }
        if (cnt % 2 == 0) cout << "NET" << '\n';
        else cout << "DA" << '\n';
    }
    return 0;
}