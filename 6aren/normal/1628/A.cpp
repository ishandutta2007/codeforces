#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]].push_back(i);
        }
        for (int i = 0; i <= n; i++) reverse(pos[i].begin(), pos[i].end());
        int cur = 0;
        vector<int> res;
        while (cur < n) {
            int best = cur;
            int foo = 0;
            for (int i = 0; i <= n; i++) {
                if (pos[i].empty()) {
                    foo = i;
                    break;
                }
                best = max(best, pos[i].back());
            }
            for (int i = 0; i < foo; i++) {
                while (!pos[i].empty() && pos[i].back() <= best) pos[i].pop_back();
            }
            res.push_back(foo);
            cur = best + 1;
        }
        cout << res.size() << '\n';
        for (int e : res) cout << e << ' ';
        cout << "\n";
    }

    return 0;
}