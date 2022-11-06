#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n+1, 0), px(n+1, 0);

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        px[i] = px[i-1] ^ a[i];
    }

    for(int i = 1; i + 2 <= n; ++i) {
        if(a[i] > (a[i+1] ^ a[i+2])) {
            cout << 1;
            return 0;
        }
    }

    assert(n <= 32 * 3);

    int ans = n + 2;
    for(int l1 = 1; l1 <= n; ++l1)
        for(int r1 = l1; r1 <= n; ++r1)
            for(int l2 = r1 + 1; l2 <= n; ++l2)
                for(int r2 = l2; r2 <= n; ++r2) {
                    int x1 = px[r1] ^ px[l1 - 1];
                    int x2 = px[r2] ^ px[l2 - 1];
                    if(x1 > x2)
                        ans = min(ans, r1 - l1 + r2 - l2);
                }

    cout << (ans > n ? -1 : ans);
    return 0;
}