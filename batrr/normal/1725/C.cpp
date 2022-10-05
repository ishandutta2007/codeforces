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

int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

//int inv(int x) {
//    return bp(x, mod - 2);
//}

int n, m;
const int maxN = 6e5 + 10;
int inv[maxN], fact[maxN], invfact[maxN];
ll pref[maxN], D[maxN];
ll S;
int cnk(int n, int k) {
    if (n < k || k < 0) return 0;
    return mult(fact[n], mult(invfact[k], invfact[n - k]));
}
void solve() {
    fact[0] = invfact[0] = invfact[1] = fact[1] = inv[1] = 1;
    for (int i = 2; i < maxN; i++) {
        fact[i] = mult(fact[i - 1], i);
        inv[i] = mult(inv[mod % i], mod - mod / i);
        invfact[i] = mult(invfact[i - 1], inv[i]);
    }
    cin >> n >> m;
    ll S = 0;
    map<ll,int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> D[i];
        pref[i] = pref[i - 1] + D[i];
        mp[pref[i]] = i;
    }
    int bad = 0;
    S = pref[n];
    int good = 0;
    if (S % 2 != 0) {
        bad = n;
    }
    else {
        bad = n;
        for (int i = 0; i < n; i++) {
            if (pref[i] < S / 2 && mp.count(S / 2 + pref[i])) {
                good++;
                bad -= 2;
            }
        }
    }
//    cout << good << " " << bad << " " << S << endl;
    int ans = 0;
    for (int i = 0; i <= good && i <= m; i++) {
        int coef = mult(fact[i], mult(cnk(m, i), cnk(good, i)));
        //(m - i) * (m - i - 1)
        if (good - i > 0 && i == m) continue;
        coef = mult(coef, pw(mult(m - i, m - i - 1), good - i));
        coef = mult(coef, pw(m - i, bad));
        ans = sum(ans, coef);
    }
    cout << ans << '\n';


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