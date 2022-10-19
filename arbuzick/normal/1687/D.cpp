#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mx = a[n - 1] * 5 + 10;
    vector<int> prv(mx, -1), nxt(mx, -1);
    int pos = n - 1;
    for (int i = mx - 1; i > a[0]; --i) {
        while (a[pos] >= i) {
            pos--;
        }
        prv[i] = a[pos];
    }
    pos = 0;
    for (int i = 0; i < a[n - 1]; ++i) {
        while (a[pos] <= i) {
            pos++;
        }
        nxt[i] = a[pos];
    }
    for (int w = 1;; ++w) {
        if (w * 1LL * w + w < a[0]) {
            continue;
        }
        int kkk = min((long long) a[0], w * 1LL * w);
        pair<int, int> segm = {0, w};
        for (int add = 0;; ++add) {
            int vl1 = (w + add) * 1LL * (w + add) + kkk - w * 1LL * w;
            int vl2 = (w + add) * 1LL * (w + add) + kkk + w + add - w * 1LL * w;
            if (prv[vl2 + 1] != -1 && prv[vl2 + 1] >= vl1) {
                segm.second = min(segm.second, vl2 - prv[vl2 + 1]);
            }
            int kek = (w + add - 1) * 1LL * (w + add - 1) + kkk + w + add - 1 - w * 1LL * w;
            if (add != 0 && nxt[kek] != -1 && nxt[kek] < vl1) {
                segm.first = max(segm.first, vl1 - nxt[kek]);
            }
            if ((w + add) * 1LL * (w + add) + w + add + kkk - w * 1LL * w >= a[n - 1]) {
                break;
            }
        }
        if (segm.first <= segm.second) {
            cout << max(0LL, w * 1LL * w + segm.first - a[0]) << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}