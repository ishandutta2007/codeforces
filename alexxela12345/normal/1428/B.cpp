#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool canRight = true;
        bool canLeft = true;
        for (char c : s) {
            if (c == '<') {
                canRight = false;
            } else if (c == '>') {
                canLeft = false;
            }
        }
        if (canRight) {
            cout << n << endl;
        } else if (canLeft) {
            cout << n << endl;
        } else {
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '-' || s[(i + 1) % n] == '-') {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
}