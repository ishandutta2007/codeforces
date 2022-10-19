#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ba = 0;
        int bb = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '(')
                ba++;
            if (c == '[')
                bb++;
            if (c == ')') {
                if (ba > 0) {
                    ba--;
                    ans++;
                }
            }
            if (c == ']') {
                if (bb > 0) {
                    bb--;
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}