#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

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
        map<string, int> ma;
        int cnt00 = 0, cnt11 = 0, cnt01 = 0, cnt10 = 0;
        vector<int> rev(n, 1), lol(n);
        int kek = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (s[0] == '0' && s.back() == '0') {
                cnt00++;
                rev[i] = 0;
                continue;
            }
            if (s[0] == '1' && s.back() == '1') {
                cnt11++;
                rev[i] = 0;
                continue;
            }
            ma[s] = i;
            if (s[0] == '0') cnt01++;
            else {
                cnt10++;
                lol[i] = 1;
            }
            kek++;
            string s1 = s;
            reverse(all(s1));
            if (ma.find(s1) != ma.end()) {
                rev[ma[s1]] = 0;
                rev[i] = 0;
                cnt01--;
                cnt10--;
                continue;
            }
        }
        if (cnt00 != 0 && cnt11 != 0 && kek == 0) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> ans;
        if (cnt01 > cnt10 + 1) {
            for (int i = 0; i < n; i++) {
                if (!rev[i]) continue;
                if (lol[i] == 1) continue;
                if (cnt01 <= cnt10 + 1) continue;
                cnt01--;
                cnt10++;
                ans.pb(i);
            }
        } else if (cnt10 > cnt01 + 1) {
            for (int i = 0; i < n; i++) {
                if (!rev[i]) continue;
                if (lol[i] == 0) continue;
                if (cnt10 <= cnt01 + 1) continue;
                cnt10--;
                cnt01++;
                ans.pb(i);
            }
        }
        cout << ans.size() << "\n";
        for (auto &c : ans) cout << c + 1 << " ";
        cout << "\n";
    }
    return 0;
}