#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> cnt;
        bool f = false;
        int now = 0;
        for (auto &c : s) {
            if (c == '0') {
                if (f) {
                    f = false;
                    cnt.pb(now);
                    now = 0;
                }
            } else {
                f = true;
                now++;
            }
        }
        if (f) cnt.pb(now);
        sort(all(cnt));
        reverse(all(cnt));
        int ans = 0;
        for (int i = 0; i < (int)cnt.size(); i += 2) ans += cnt[i];
        cout << ans << "\n";
    }
    return 0;
}