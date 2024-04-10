#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int d, m;
        cin >> d >> m;
        int mxBit = 0;
        for (int i = 30; i >= 0; i--) {
            if (bit(d, i) == 1) {
                mxBit = i;
                break;
            }
        }
        vector<int> cnt(mxBit + 1);
        for (int i = 0; i < mxBit; i++) {
            cnt[i] = (1 << (i + 1)) - (1 << i); 
        }
        cnt[mxBit] = d - (1 << mxBit) + 1;
        long long ans = 1;
        for (int i = 0; i <= mxBit; i++) {
            ans += ans * (cnt[i]);
            ans %= m;
        }
        ans = (ans - 1 + m) % m;
        cout << ans << '\n';
    }
    return 0;
}