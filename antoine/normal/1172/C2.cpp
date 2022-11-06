#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;

ll modPow(ll n, ll k) {
    ll res = 1;
    for (n %= mod; k; k >>= 1) {
        if (k & 1)
            res = res * n % mod;
        n = n * n % mod;
    }
    return res;
}

ll modInv(ll x) {
    return modPow(x, mod - 2);
}

const int MxM = 3009;
ll dp[MxM + 9][MxM + 9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, M;
    cin >> n >> M;
    vector<int> a(n), w(n);
    for (int &x : a)
        cin >> x;
    for (int &x : w)
        cin >> x;

    int likesW = 0, dislikesW = 0;
    for (int i = 0; i < n; ++i)
        (a[i] ? likesW : dislikesW) += w[i];


    ll ELike = 0, EDislike = 0;
    for (int c1 = 0; c1 <= M; ++c1)
        for (int c2 = 0; c2 <= min(M - c1, dislikesW); ++c2) {
            ll &res = dp[c1][c2] = 0;
            if (!c1 && !c2)
                res = 1;
            else {
                const int total = likesW + c1 + dislikesW - c2;
                if (c1)
                    res += dp[c1 - 1][c2] * (likesW + (c1 - 1)) % mod * modInv(total - 1);
                if (c2)
                    res += dp[c1][c2 - 1] * (dislikesW - (c2 - 1)) % mod * modInv(total + 1);
                res %= mod;
            }
            if (c1 + c2 == M) {
                ELike += (likesW + c1) * res;
                EDislike += (dislikesW - c2) * res;
                ELike %= mod, EDislike %= mod;
            }
        }

    ELike *= modInv(likesW);
    EDislike *= modInv(dislikesW);
    ELike %= mod, EDislike %= mod;

    for (int i = 0; i < n; ++i) {
        ll res = w[i] * (a[i] ? ELike : EDislike) % mod;
        cout << res << '\n';
    }

    return 0;
}