#include <bits/stdc++.h>

using namespace std;

string toLower(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    map<string, int> cnt;
    int ans = 0;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y >> y;
        x = toLower(x);
        y = toLower(y);
        cnt[x] = cnt[y] + 1;
        ans = max(ans, cnt[x]);
    }
    cout << ans + 1 << "\n";
    return 0;
}