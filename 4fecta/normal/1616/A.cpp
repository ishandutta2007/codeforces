#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, a[105];
        set<int> s;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (s.count(a[i])) s.insert(-a[i]);
            else s.insert(a[i]);
        }
        printf("%lld\n", s.size());
    }

    return 0;
}