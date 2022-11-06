#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int _t;
    cin >> _t;
    while(_t--)
    {
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    int m1 = -1, m2 = -1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int &y = (i < k1 ? m1 : m2);
        y = max(y, x);
    }
    cout << (m1 > m2 ? "YES" : "NO") << '\n';
}
    return 0;
}