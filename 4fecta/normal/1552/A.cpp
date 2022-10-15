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
        int n;
        string s;
        cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end());
        int ans = 0;
        for (int i= 0; i < n; i++) if (s[i] != t[i]) ans++;
        printf("%lld\n", ans);
    }

    return 0;
}