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
        string s;
        cin >> s;
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i + 2 < n; i++) {
            if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') ans.pb(i + 1);
            if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
                if (i + 3 < n && s[i + 3] != 'o') {
                    ans.pb(i + 2);
                    s[i + 2] = '#';
                }
                else ans.pb(i + 1);
            }
        }
        cout << ans.size() << "\n";
        for (auto &c : ans) cout << c + 1 << " ";
        cout << "\n";
    }
    return 0;
}