#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int ll

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> bal = {0};
    for (char c : s) {
        int x = 1;
        if (c == ')')
            x = -1;
        bal.push_back(bal.back() + x);
    }
    if (bal.back() == 0 && *min_element(bal.begin(), bal.end()) >= -1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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