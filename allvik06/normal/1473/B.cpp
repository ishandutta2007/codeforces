#include <bits/stdc++.h>

using namespace std;
#define int long long
const int INF = 1e9;

inline int gcd(int a, int b) {
    for (; b > 0; a %= b, swap(a, b)) {}
    return a;
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int res = -1;
        for (int ans = min(a.size(), b.size()); ans > 0; --ans) {
            bool f = true;
            if (a.size() % ans != 0 || b.size() % ans != 0) continue;
            for (int i = 0; i < a.size(); i += ans) {
                if (a.substr(i, ans) != a.substr(0, ans)) f = false;
            }
            for (int i = 0; i < b.size(); i += ans) {
                if (b.substr(i, ans) != b.substr(0, ans)) f = false;
            }
            if (a.substr(0, ans) != b.substr(0, ans)) f = false;
            if (f) {
                res = ans;
                break;
            }
        }
        if (res == -1) cout << res << "\n";
        else {
            int kol = a.size() / res * b.size() / res / gcd(a.size() / res, b.size() / res);
            for (int i = 0;  i < kol; ++i) cout << a.substr(0, res);
            cout << "\n";
        }
    }
}