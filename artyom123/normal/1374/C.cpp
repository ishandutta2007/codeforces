#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

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
        int ans = 0, cnt = 0;
        for (auto &c : s) {
            if (c == '(') cnt++;
            else cnt--;
            if (cnt < 0) ans = max(ans, abs(cnt));
        }
        cout << ans << "\n";
    }
    return 0;
}