#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;

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
        string ans = "";
        int cnt = 0;
        for (auto &c : s) cnt += (c == '0');
        for (int i = 0; i < n; i++) {
            cnt -= (s[i] == '0');
            if (ans.size() && ans.back() == '1' && cnt > 0) continue;
            while (ans.size() && ans.back() == '1' && s[i] == '0') ans.pop_back();
            ans += s[i];
        }
        cout << ans << "\n";
    }
    return 0;
}