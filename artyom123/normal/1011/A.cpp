#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <int> a(26);
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a']++;
    }
    int ans = 0, now = 0;
    int p = -2;
    for (int i = 0; i < 26 && now < k; i++) {
        if (i >= p + 2 && a[i] > 0) {
           now++;
           ans += (i + 1);
           p = i;
        }
    }
    if (now < k) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}