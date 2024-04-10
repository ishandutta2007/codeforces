#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string now = s;
    k--;
    while (k > 0) {
        int maxx = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (now.substr(0, i + 1) == s.substr(s.size() - i - 1, i + 1)) {
                maxx = max(maxx, i + 1);
            }
        }
        now = s.substr(0, s.size() - maxx) + now;
        k--;
    }
    cout << now;
}