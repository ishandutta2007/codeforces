#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

const ll mx = 1000000000;

#define X first
#define Y second

ll n;
void solve() {
    cin >> n;
    ll l = 0;
    ll r = 4 * n + 228;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        ll how_many = 0;
        if (mid >= 1) how_many++;
        if (mid >= 4) how_many++;
        if (mid >= 2) how_many += ((mid - 2) / 4) + 1;
        if (mid - how_many >= n) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}