#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int solve(int n) {
        if(n % 4 == 0) {
            return n / 4;
        } else if(n % 4 == 2) {
            if(n == 2) {
                return -1;
            } else {
                n -= 6;
                return n / 4 + 1;
            }
        } else if(n % 4 == 1) {
            if(n == 1 || n == 5) {
                return -1;
            } else {
                n -= 9;
                return n / 4 + 1;
            }
        } else {
            if(n == 3 || n == 7 || n == 11) {
                return -1;
            } else {
                n -= 15;
                return n / 4 + 2;
            }
        }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}