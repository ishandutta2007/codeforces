#include <bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t

const int maxn = 2e5 + 42, logn = 20;
const int inf = 1e9;

int bpow(int x, int n, int m) {
    return n ? n % 2 ? x * bpow(x, n - 1, m) % m : bpow(x * x % m, n / 2, m) : 1;
}

int inter(int a, int b, int c, int d) {
    return max<int>(0, min(d, b) - max(a, c) + 1);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int la, ra, ta;
    int lb, rb, tb;
    cin >> la >> ra >> ta;
    cin >> lb >> rb >> tb;
    int tg = __gcd(ta, tb);
    int min_dist = ((lb - la) % tg + tg) % tg;
    int ans1 = inter(la, ra, la + min_dist, la + min_dist + (rb - lb));
    int ans2 = inter(la, ra, la + min_dist - tg, la + min_dist - tg + (rb - lb));
    cout << max(ans1, ans2) << endl;
    return 0;
}