#include <bits/stdc++.h>
using namespace std;
const int N = 100000, C = 350;

int power[N], cnt[N], to[N], lst[N], n;
// cnt -> time to leave current block
// to -> jump to where
// lst -> last position

void update_block(int id) {
    int l = id * C, r = min((id + 1) * C, n);
    for (int i = r - 1; i >= l; --i) {
        if (i + power[i] >= r) {
            // outside the block
            cnt[i] = 1;
            to[i] = i + power[i];
            lst[i] = i;
        } else {
            // inside the block 
            cnt[i] = cnt[i + power[i]] + 1;
            to[i] = to[i + power[i]];
            lst[i] = lst[i + power[i]];
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> power[i];
    for (int i = 0; i * C < n; ++i)
        update_block(i);
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, v;
            cin >> p >> v, --p;
            power[p] = v;
            update_block(p / C);
        } else {
            int p;
            cin >> p, --p;
            int ans1 = 0, ans2 = 0;
            while (p < n) {
                ans1 = lst[p];
                ans2 += cnt[p];
                p = to[p];
            }
            cout << ans1 + 1 << ' ' << ans2 << '\n';
        }
    }
}