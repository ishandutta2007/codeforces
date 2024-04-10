#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

const int INF = 1e9;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        if (s[i] != 2 && s[n - i - 1] == 2) {
            if (s[i] == 0) {
                ans += a;
            }
            else {
                ans += b;
            }
            continue;
        }
        else if (s[i] == 2 && s[n - i - 1] == 2) {
            if (i != n - i - 1) {
                ans += 2 * min(a, b);
                continue;
            }
            ans += min(a, b);
            continue;
        }
        else if (s[i] == 2 && s[n - i - 1] != 2) {
            if (s[n - i - 1] == 0) {
                ans += a;
            }
            else {
                ans += b;
            }
            continue;
        }
        else if (s[i] == s[n - i - 1]) {
            continue;
        }
        else {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}