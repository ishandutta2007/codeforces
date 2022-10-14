#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
 
const long long INF = 1e18 + 1;
const long long mod = 1e9 + 7;
 
long long my_pow(long long n, long long m) {
    if (m == 0) return 1;
    if (m == 1) return n;
    long long now = my_pow(n, m / 2);
    if (m % 2 == 0) return (now * now) % mod;
    return (((now * now) % mod) * n) % mod;
}
 
long long n, p;
 
void lolkek(vector<pair<long long, long long>> &k, int ind, long long need, bool &f) {
    if (need > 1e7) return;
    if (ind == n) return;
    if (k[ind].se >= need) {
        f = true;
        k[ind].se -= need;
        return;
    }
    long long res = 1;
    for (int j = 0; j < k[ind].fi - k[ind + 1].fi; j++) {
        res *= p;
        if (res > 1e10) return;
    }
    lolkek(k, ind + 1, (need - k[ind].se) * res, f);
    if (f == false) return;
    k[ind].se = 0;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        vector<pair<long long, long long>> k;
        map<int, int> ma;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ma[x]++;
        }
        if (p == 1) {
            cout << n % 2 << "\n";
            continue;
        }
        for (auto &c : ma) k.pb(c.fi, c.se);
        sort(all(k));
        reverse(all(k));
        long long ans = 0;
        n = k.size();
        for (int i = 0; i < n; i++) {
            if (k[i].se % 2 == 0) continue;
            bool f = false;
            k[i].se = 0;
            lolkek(k, i, 1, f);
            if (f == true) continue;
            for (int o = i + 1; o < n; o++) ans += k[o].se * my_pow(p, k[o].fi); ans %= mod;
            ans = (my_pow(p, k[i].fi) - ans + mod * mod) % mod;
            break;
        }
        cout << ans << "\n";
    }
    return 0;
}