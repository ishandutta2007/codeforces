#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, s, k, x;
        cin >> n >> s >> k;
        set <int> ss;
        for (int i = 1; i <= k; ++i) cin >> x, ss.insert(x);
        int ans = 0;
        while (true) {
            if (s + ans <= n && ss.find(s + ans) == ss.end()) break;
            if (s - ans >= 1 && ss.find(s - ans) == ss.end()) break;
            ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}