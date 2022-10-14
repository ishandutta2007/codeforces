#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, t, v;
    cin >> q;
    cin >> t >> v;
    q--;
    vector <int> limit;
    vector <int> sign;
    int cur_v = v, ans = 0;
    bool is = true, is2 = true;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> v;
            cur_v = v;
            while (limit.size() && limit.back() < cur_v) ans++, limit.pop_back();
        } else if (t == 2) {
            while (sign.size() && sign.back() == 0) ans++, sign.pop_back();
        } else if (t == 3) {
            cin >> v;
            if (cur_v <= v) limit.push_back(v);
            else ans++;
        } else if (t == 4) {
            sign.clear();
        } else if (t == 5) {
            limit.clear();
        } else {
            sign.push_back(0);
        }
    }
    cout << ans;
}