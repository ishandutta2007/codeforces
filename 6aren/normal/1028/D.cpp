#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    set<int> s;
    int n;
    cin >> n;
    long long ans = 1;
    int l = 0, r = 1e9;
    int cnt_mid = 0;

    for (int i = 1; i <= n; i++) {
        string t;
        int p;
        cin >> t >> p;
        if (t == "ADD") {
            s.insert(p);
            if (p > l && p < r) cnt_mid++;
        } else {
            if (p < l || p > r) return cout << 0, 0;
            s.erase(p);
            if (p != r && p != l) ans = ans * 2 % MOD;
            cnt_mid = 0;
            auto it = s.upper_bound(p);
            if (it != s.end()) r = *it;
            else r = 1e9;
            if (it == s.begin()) l = 0;
            else {
                it--;
                l = *it;
            } 
        }
    }

    cout << 1LL * ans * (cnt_mid + 1) % MOD << '\n';
    return 0;
}