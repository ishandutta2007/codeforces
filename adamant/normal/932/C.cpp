#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    for(int x = 0; x <= n; x++) {
        int y = (n - x * a) / b;
        if(a * x + b * y == n && y >= 0) {
            vector<int> ans(n);
            int start = 0;
            for(int i = 0; i < x; i++) {
                for(int j = 0; j < a; j++) {
                    ans[j + start] = start + (j + 1) % a;
                }
                start += a;
            }
            for(int i = 0; i < y; i++) {
                for(int j = 0; j < b; j++) {
                    ans[j + start] = start + (j + 1) % b;
                }
                start += b;
            }
            for(auto it: ans) {
                cout << it + 1 << ' ';
            }
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}