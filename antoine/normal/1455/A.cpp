#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f() {
    string s;
    cin >> s;
    return s.length();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        auto res = f();
        cout << res << '\n';
    }
    return 0;
}