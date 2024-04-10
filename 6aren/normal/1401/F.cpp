#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int n, q;
int bl;
int sum[1 << 10];
int a[1 << 19];

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];
    bl = n / 2;
    for (int i = 0; i < (1 << bl); i++) {
        int pref = (i << (n - bl));
        for (int j = 0; j < (1 << (n - bl)); j++) {
            int id = pref + j;
            sum[i] += a[id];
        }
    }

    int sumXor = 0;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, k;
            cin >> x >> k;
            x--;
            int prev = (x ^ sumXor);
            sum[x / (1 << (n - bl))] += k - a[prev];
            a[prev] = k;
        } else if (type == 2) {
            int k;
            cin >> k;
            sumXor ^= ((1 << k) - 1);
            if (k > n - bl) {
                int la = (1 << (k - n + bl)) - 1;
                for (int i = 0; i < (1 << bl); i += la + 1) {
                    for (int j = 0; j < (la + 1) / 2; j++) {
                        swap(sum[i + j], sum[i + (j ^ la)]);
                    }
                }

            }
        } else if (type == 3) {
            int k;
            cin >> k;
            sumXor ^= (1 << k);
            if (k >= n - bl) {
                int foo = k - (n - bl);
                for (int i = 0; i < (1 << bl); i += (1 << (foo + 1))) {
                    for (int j = 0; j < (1 << foo); j++) {
                        swap(sum[i + j], sum[i + j + (1 << foo)]);
                    }
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int bll = l / (1 << (n - bl));
            int blr = r / (1 << (n - bl));
            int ans = 0;
            if (bll == blr) {
                for (int i = l; i <= r; i++) {
                    int act_id = (i ^ sumXor);
                    ans += a[act_id];
                }
            } else {
                while (l < (bll + 1) * (1 << (n - bl))) {
                    ans += a[l ^ sumXor];
                    l++;
                }
                while (r >= blr * (1 << (n - bl))) {
                    ans += a[r ^ sumXor];
                    r--;
                }
                for (int i = bll + 1; i < blr; i++) ans += sum[i];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}