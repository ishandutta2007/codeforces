#include <bits/stdc++.h>
using namespace std;
int n, r;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> r;
        vector<int> a;
        for (int i = 1, u; i <= n; i++) cin >> u, a.push_back(u);
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int del = 0, ans = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] - del <= 0) break;
            ans++, del += r;
        }
        printf("%d\n", ans);
    }
}