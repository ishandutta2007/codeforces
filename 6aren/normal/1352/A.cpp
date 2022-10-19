#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int ans = 0;
        for (char ch : s) {
            if (ch != '0') ans++;
        }
        cout << ans << '\n';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' != 0) {
                cout << s[i];
                for (int j = i + 1; j < s.size(); j++) {
                    cout << 0;
                }
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}