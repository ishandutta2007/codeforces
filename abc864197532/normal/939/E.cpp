#include <bits/stdc++.h>
using namespace std;

const int N = 2001, mod = 1e9 + 7;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <int> now;
    vector <long long> pre = {0};
    int q, t, x;
    cin >> q;
    cout << fixed << setprecision(10);
    auto ask = [&](int a) {
        return (long double)(now.back()) - (long double)(now.back() + pre[a]) / (a + 1);
    };
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            now.push_back(x);
            pre.push_back(pre.back() + x);
        } else {
            int l = 0, r = now.size();
            while (r - l > 1) {
                int mid = l + r >> 1;
                (ask(mid) < ask(mid + 1) ? l : r) = mid;
            }
            cout << ask(r) << '\n';
        }
    }
}