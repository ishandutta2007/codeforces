#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 2e5 + 9;
string s[maxn];
int n;

void solve() {
    cin >> n;
    bool ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i][0] == s[i].back()) {
            ans = 1;
        }
    }
    if (!ans) {
        for (int len = 2; len <= 3; len++) {
            set<string> m;
            for (int i = 0; i < n; i++) {
                if (s[i].size() != len) {
                    continue;
                }
                if (m.find(s[i]) != m.end()) {
                    ans = 1;
                    break;
                }
                string x = s[i];
                reverse(all(x));
                m.insert(x);
            }
        }
    }
    if (!ans) {
        for (int len = 2; len <= 3; len++) {
            set<string> m;
            for (int i = 0; i < n; i++) {
                if (s[i].size() == len) {
                    string x = s[i];
                    if (x.size() == 3) {
                        x = x.substr(1, 2);
                    }
                    if (m.find(x) != m.end()) {
                        ans = 1;
                        break;
                    }
                } else {
                    string x = s[i];
                    if (x.size() == 3) {
                        x.pop_back();
                    }
                    reverse(all(x));
                    m.insert(x);
                }
            }
        }
    }
    if (ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}