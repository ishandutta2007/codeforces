#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005, MV = 1e6 + 5;

int e, n, t, a[MN], sieve[MV];

int32_t main() {
    boost();

    sieve[1] = 1;
    for (int i = 2; i < MV; i++) {
        if (sieve[i]) continue;
        for (int j = i + i; j < MV; j += i) sieve[j] = 1;
    }
    cin >> t;
    while (t--) {
        cin >> n >> e;
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i], ans -= !sieve[a[i]];
        for (int i = 1; i <= e; i++) {
            vector<int> v;
            for (int j = i; j <= n; j += e) v.push_back(a[j]);
            for (int j = 0; j < v.size(); j++) {
                if (sieve[v[j]]) continue;
                int l = j, r = j;
                while (l > 0 && v[l - 1] == 1) l--;
                while (r < v.size() - 1 && v[r + 1] == 1) r++;
                ans += (j - l + 1) * (r - j + 1);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}