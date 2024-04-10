#include <bits/stdc++.h>

using namespace std;

int a[10];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto c : s) {
        if (c == 'L') {
            for (int i = 0; i <= 9; ++i) {
                if (a[i] == 0) {
                    a[i] = 1;
                    break;
                }
            }
        }
        else if (c == 'R') {
            for (int i = 9; i >= 0; --i) {
                if (a[i] == 0) {
                    a[i] = 1;
                    break;
                }
            }
        }
        else {
            a[c - '0'] = 0;
        }
    }
    for (int i = 0; i < 10; ++i) cout << a[i];
    return 0;
}