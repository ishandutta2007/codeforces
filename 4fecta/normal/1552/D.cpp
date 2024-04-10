#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 12;

int t, n, a[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        set<int> s;
        for (int i = 1; i <= n; i++) cin >> a[i], a[i] = abs(a[i]), s.insert(a[i]);
        sort(a + 1, a + n + 1);
        int ok = s.size() < n;
        for (int msk = 0; msk < 1 << n && !ok; msk++) {
            for (int neg = msk; neg >= 0; neg = (neg - 1) & msk) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if (msk & (1 << i)) {
                        if (neg & (1 << i)) sum += a[i + 1];
                        else sum -= a[i + 1];
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (msk & (1 << i)) continue;
                    if (a[i + 1] == sum) ok = 1;
                }
                if (!neg) break;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}