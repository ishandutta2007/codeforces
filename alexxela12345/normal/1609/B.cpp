#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

string s;
int ans = 0;

int get(int i) {
    if (i >= 0 && i + 3 <= (int) s.size()) {
        if (s.substr(i, 3) == "abc") {
            return 1;
        }
    }
    return 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i + 3 <= n; i++) {
        ans += get(i);
    }
    while (q--) {
        int i;
        char c;
        cin >> i;
        i--;
        cin >> c;
        ans -= get(i) + get(i - 1) + get(i - 2);
        s[i] = c;
        ans += get(i) + get(i - 1) + get(i - 2);
        cout << ans << endl;
    }    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}