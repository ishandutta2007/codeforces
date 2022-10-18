#include <bits/stdc++.h>

using namespace std;
#define link alflak
#define fpos ladla

#define int int64_t
#define all(x) begin(x), end(x)
#define rall(x) x.rbegin(), x.rend()

const int maxn = 1e5 + 42;

void fail() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    int p[n + 1];
    p[0] = 0;
    map<int, int> cnt;
    int mask = (1LL << k) - 1;
    cnt[0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        p[i + 1] = p[i] ^ a[i];
        int A = p[i + 1];
        int B = p[i + 1] ^ mask;
        if(A % 2 == 0) {
            cnt[A]++;
        } else {
            cnt[B]++;
        }
    }
    int ans = 0;
    for(auto it: cnt) {
        int A = it.second / 2;
        int B = it.second - A;
        ans += A * (A - 1) / 2 + B * (B - 1) / 2;
    }
    cout << n * (n + 1) / 2 - ans << endl;
    return 0;
}