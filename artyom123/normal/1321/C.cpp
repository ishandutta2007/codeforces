#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c = 'z'; c >= 'b'; c--) {
        while (1) {
            bool f = false;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c && ((i > 0 && s[i - 1] == c - 1) || (i + 1 < s.size() && s[i + 1] == c - 1))) {
                    s.erase(s.begin() + i);
                    f = true;
                    break;
                }
            }
            if (!f) break;
        }
    }
    cout << n - s.size();
    return 0;
}