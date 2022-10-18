#include<bits/stdc++.h>

using namespace std;

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int z = 25; z >= 0; --z) {
        int find = 1;
        while (find) {
            find = 0;
            for (int i = 0; i < (int)s.size(); ++i) {
                if (s[i] == char('a' + z)) {
                    int ok = 0;
                    if (i > 0 && s[i - 1] - 'a' == z - 1) ok = 1;
                    if (i < (int)s.size() - 1 && s[i + 1] - 'a' == z - 1) ok = 1;
                    if (ok) {
                        ans++;
                        find = 1;
                        string go = "";
                        for (int j = 0; j < (int)s.size(); ++j) if (j != i) go += s[j];
                        s = go;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}