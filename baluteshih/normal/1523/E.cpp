#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MOD = 1e9 + 7, MAXN = 200000;
int J[MAXN + 5] = {1}, invJ[MAXN + 5] = {1};

void add(int &x, int val) {
    x += val;
    if (x > MOD)
        x -= MOD;
}

int C(ll n, ll m) {
    if (n < m) return 0;
    return (ll)J[n] * invJ[m] % MOD * invJ[n - m] % MOD;
}

int invC(int n, int m) {
    if (n < m) {
        assert(0);
        return 0;
    }
    return (ll)invJ[n] * J[m] % MOD * J[n - m] % MOD;
}

int pw(int a, int n) {
    int rt = 1;
    for (; n; n >>= 1, a = (ll)a * a % MOD)
        if (n & 1)
            rt = (ll)rt * a % MOD;
    return rt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i <= MAXN; ++i)
        J[i] = (ll)J[i - 1] * i % MOD;
    invJ[MAXN] = pw(J[MAXN], MOD - 2);
    for (int i = MAXN - 1; i >= 0; --i)
        invJ[i] = (ll)invJ[i + 1] * (i + 1) % MOD;
    int t;
    cin >> t;
    while (t--) {
        int n, k, ans = 0;
        cin >> n >> k;
        for (int i = 0; i <= n; ++i)
            add(ans, (ll)C(n + k - 1 - (ll)i * (k - 1), i) * invC(n, i) % MOD);
        cout << ans << "\n";
    }
}