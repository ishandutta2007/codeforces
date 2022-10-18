#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, ans;
        cin >> n >> s;
        if (n == 1 || s[0] <= s[1]) {
            cout << s[0] << s[0] << "\n";
            continue;
        }
        ans.pb(s[0]);
        for (int i = 1; i < n; ++i)
            if (s[i] <= ans.back())
                ans.pb(s[i]);
            else
                break;
        cout << ans;
        reverse(ALL(ans));
        cout << ans << "\n";
    }
}