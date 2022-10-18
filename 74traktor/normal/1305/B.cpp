#include<bits/stdc++.h>

using namespace std;

int used[1005];

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector < vector < int > > ans;
    while (1) {
        int L = 0, R = (int)s.size() - 1;
        set < int > Q;
        while (L < R) {
            while (L < (int)s.size()) {
                if (s[L] == '(' && used[L] == 0) break;
                ++L;
            }
            while (R >= 0) {
                if (s[R] == ')' && used[R] == 0) break;
                --R;
            }
            if (L > R) break;
            used[L] = 1, used[R] = 1;
            Q.insert(L), Q.insert(R);
            L++, R--;
        }
        if ((int)Q.size() == 0) break;
        ans.emplace_back();
        for (auto key : Q) ans.back().push_back(key);
    }
    cout << ans.size() << '\n';
    for (auto key : ans) {
        cout << key.size() << '\n';
        for (auto elem : key) cout << elem + 1 << " ";
        cout << '\n';
    }
    return 0;
}