#include <bits/stdc++.h>

using namespace std;

int used[30];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << "Yes" << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (used[s[i] - 'a'] == 1) {
            cout << "Yes" << '\n';
            return 0;
        }
        used[s[i] - 'a'] = 1;
    }
    cout << "No" << '\n';
    return 0;
}