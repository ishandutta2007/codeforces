#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    long long ans = 0;
    while (n--) {
        int x;
        cin >> x;
        s.insert(x);
        ans += x;
    }
    int lst = *s.rbegin();
    s.erase(--s.end());
    while (!s.empty()) {
        if (lst + *s.begin() <= m) {
            auto it = s.upper_bound(m - lst);
            lst = *prev(it);
            s.erase(prev(it));
        } else {
            lst = *s.rbegin();
            s.erase(--s.end());
            ans++;
        }
    }
    cout << ans + 1 << "\n";
    return 0;
}