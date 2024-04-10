#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double
#define mp make_pair
#define ull unsigned long long

const int INF = 1e9 + 1;
const ll INFLL = (ll)1e18 + 1;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 10;
        for (int mask = 0; mask < (1 << 10); mask++) {
            bool ok = 1;
            for (int i = 0; i < 10; i++) {
                if (s[i] == '?') continue;
                if (s[i] == '0' && (mask & (1 << i))) ok = 0;
                if (s[i] == '1' && !(mask & (1 << i))) ok = 0;
            }
            if (!ok) continue;
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0 && (mask & (1 << i))) cnt1++;
                if (i % 2 == 1 && (mask & (1 << i))) cnt2++;
                int mx1 = cnt1, mx2 = cnt2;
                if (i % 2 == 0) {
                    mx1 += (10 - i) / 2 - 1;
                    mx2 += (10 - i) / 2;
                } else {
                    mx1 += (10 - i) / 2;
                    mx2 += (10 - i) / 2;
                }
                if (cnt1 > mx2 || cnt2 > mx1) {
                    ans = min(ans, i + 1);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}