#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int MOD = 998244353;
const int N = 300005;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y % 2) res = 1LL * res * x % MOD;
        x = 1LL * x * x % MOD;
        y >>= 1;
    }
    return res;
}

int inv(int x) {
    return power(x, MOD - 2);
}

int fac[N], ifac[N];

void init_combi() {
    fac[0] = 1;
    ifac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = inv(fac[i]); 
    }
}

int C(int n, int k) {
    if (n < k) return 0;
    return 1LL * ifac[k] * ifac[n - k] % MOD * fac[n] % MOD;
}

main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    init_combi();
    int n, k;
    cin >> n >> k;
    vector<pair<int, ii>> ev;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        ev.pb({l, {1, i}});
        ev.pb({r + 1, {0, i}});
    }
    sort(all(ev));

    int i = 0;
    set<int> s;
    int ans = 0;
    while (i < ev.size()) {
        int cur = ev[i].x;
        while (i < ev.size() && ev[i].y.x == 0) {
            s.erase(ev[i].y.y);
            i++;
        }
        int n_old = s.size();
        while (i < ev.size() && ev[i].x == cur) {
            s.insert(ev[i].y.y);
            i++;
        }
        ans = (ans + C(s.size(), k) - C(n_old, k)) % MOD;
        if (ans < 0) ans += MOD;
    } 
    cout << ans;
    return 0;
}