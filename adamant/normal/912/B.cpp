#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = 0;
    int cur = 1;
    while(cur <= n) {
        cur *= 2;
    }
    cur /= 2;
    while(cur && k) {
        ans |= cur;
        cur /= 2;
        if(k == 1) {
            ans = n;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}