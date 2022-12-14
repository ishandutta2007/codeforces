#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int ans = 1;
    int bef = 0;
    for (int i = 1; i <= n; i++) {
        int x = bef * 3LL % MOD;
        int y = (bef * 2LL + ans) % MOD;
        ans = x;
        bef = y;
    }
    cout << ans;
}