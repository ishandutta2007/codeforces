#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<multiset<int>> b(2e5 + 228);
    for (int x : a) {
        int cur = 0;
        b[x].insert(cur++);
        while (x) {
            x /= 2;
            b[x].insert(cur++);
        }
    }
    int best_ans = 1e9;
    for (int i = 0; i < (int) b.size(); i++) {
        if (b[i].size() >= k) {
            int cnt = 0;
            int ans = 0;
            for (int el : b[i]) {
                cnt++;
                ans += el;
                if (cnt == k)
                    break;
            }
            best_ans = min(best_ans, ans);
        }
    }
    cout << best_ans << endl;
}