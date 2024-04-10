#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, A1[1000001], A[1000001], B[1000001], ans;

inline void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}

inline void sub(int &x, int y) {
    x -= y;
    if(x < 0) x += mod;
}

inline void upd(int x) {
    add(A[x], A[x]);
    add(A[x], A1[x] + 1);
    add(A1[x], A1[x] + 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int y = 1; y * y <= x; y++)
            if(x % y == 0) {
                upd(y);
                if(y * y != x) upd(x / y);
            }
    }
    for(int i = 1000000; i > 1; i--) {
        B[i] = A[i];
        for(int j = i + i; j <= 1000000; j += i) sub(B[i], B[j]);
        ans = (ans + 1LL * i * B[i]) % mod;
    }
    cout << ans;
}