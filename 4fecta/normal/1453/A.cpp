#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        int n, m, a[105], b[105];
        set<int> s;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
        for (int j = 1; j <= m; j++) cin >> b[j], s.insert(b[j]);
        cout << n + m - s.size() << "\n";
    }

    return 0;
 }