#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> divs(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                divs[j].push_back(i);
            }
        }
        string s;
        cin >> s;
        vector<bool> banned(n + 1);
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                // add to banned
                for (int e : divs[i]) banned[e] = true;
            } else {
                // find smallest div that is not banned
                for (int e : divs[i]) {
                    if (!banned[e]) {
                        res += e;
                        break;
                    }
                }
            }
        }
        cout << res << '\n';
    }
    return 0;
}