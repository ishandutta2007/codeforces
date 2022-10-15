#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 1000005;

int t, n, m, a[MN], b[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        sort(b + 1, b + m + 1);
        int g = b[1];
        for (int i = 2; i <= m; i++) g = __gcd(g, b[i]); //proc mod g
        int ans = 0;
        for (int i = 1; i <= g; i++) {
            vector<int> v;
            int neg = 0;
            for (int j = i; j <= n; j += g) {
                v.push_back(abs(a[j]));
                if (a[j] < 0) neg++;
            }
            sort(v.begin(), v.end());
            if (neg % 2 == 1) {
                ans -= v[0];
            } else {
                ans += v[0];
            }
            for (int j = 1; j < v.size(); j++) ans += v[j];
        }
        int ans1 = 0;
        for (int i = 1; i <= g; i++) {
            vector<int> v;
            int neg = 1;
            for (int j = i; j <= n; j += g) {
                v.push_back(abs(a[j]));
                if (a[j] < 0) neg++;
            }
            sort(v.begin(), v.end());
            if (neg % 2 == 1) {
                ans1 -= v[0];
            } else {
                ans1 += v[0];
            }
            for (int j = 1; j < v.size(); j++) ans1 += v[j];
        }
        printf("%lld\n", max(ans, ans1));
    }

    return 0;
}