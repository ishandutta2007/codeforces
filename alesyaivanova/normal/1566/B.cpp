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

const int maxn = 1e5 + 9;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != s[i + 1])
                cnt++;
        }
        if (cnt == 0 && s[0] == '1') {
            cout << "0\n";
        } else if (cnt == 0 || cnt == 1 || (cnt == 2 && s[0] == '1')) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
}