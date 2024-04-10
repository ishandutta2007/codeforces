#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 2005;

int t, n, a[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ev, od;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 2) od.push_back(a[i]);
            else ev.push_back(a[i]);
        }
        int ans = 0;
        for (int p : ev) {
            for (int q : od) {
                if (__gcd(p, 2 * q) > 1) ans++;
            }
        }
        for (int i = 0; i < ev.size(); i++) {
            for (int j = i + 1; j < ev.size(); j++) {
                if (__gcd(ev[i], ev[j] * 2) > 1) ans++;
            }
        }
        for (int i = 0; i < od.size(); i++) {
            for (int j = i + 1; j < od.size(); j++) {
                if (__gcd(od[i], od[j] * 2) > 1) ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}