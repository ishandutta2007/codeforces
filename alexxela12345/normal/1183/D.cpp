#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;
            cnt[x]++;
        }
        sort(cnt.begin(), cnt.end());
        int ans = 0;
        int last = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            ans += min(last, cnt[i]);
            last = max(0, min(last, cnt[i]) - 1);
        }
        cout << ans << endl;
    }
}