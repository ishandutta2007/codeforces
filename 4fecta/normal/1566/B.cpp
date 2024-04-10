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
        string s;
        cin >> s;
        int ans = 2;
        vector<int> pos;
        for (int i = 0; i < s.size(); i++) if (s[i] == '0') pos.push_back(i);
        if (pos.empty()) ans = 0;
        else {
            bool ok = 1;
            for (int i = 1; i < pos.size(); i++) if (pos[i] != pos[i - 1] + 1) ok = 0;
            if (ok) ans = 1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}