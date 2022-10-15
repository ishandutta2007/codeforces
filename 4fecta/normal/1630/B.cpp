#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, k, a[MN], freq[MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i], freq[a[i]]++;
        int amt = (n + k + 1) / 2, cnt = 0;
        int r = 0;
        int ans = 0x3f3f3f3f, x = 0, y = 0;
        for (int l = 1; l <= n; l++) {
            while (r + 1 <= n && cnt < amt) r++, cnt += freq[r];
            if (cnt >= amt && ans > r - l) ans = r - l, x = l, y = r;
            cnt -= freq[l];
        }
        printf("%lld %lld\n", x, y);
        vector<pii> out;
        int bal = 0, lft = 1;
        for (int i = 1; i <= n; i++) {
            if (x <= a[i] && a[i] <= y) bal++;
            else bal--;
            if (bal > 0) {
                if (out.size() < k - 1) out.push_back({lft, i});
                else if (out.size() == k - 1) {
                    out.push_back({lft, n});
                    break;
                }
                lft = i + 1;
                bal = 0;
            }
        }
        assert(out.size() == k);
        for (pii p : out) printf("%lld %lld\n", p.f, p.s);
        for (int i = 1; i <= n; i++) freq[i] = 0;
    }

    return 0;
}