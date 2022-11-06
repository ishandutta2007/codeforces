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

const int MxM = 6009;
ll dp[51][51][51];
ll mdInv[(int)3e5 + 9];

ll f(const bool Like, const int MyW, const int LikesW, const int DislikesW, const int M) {

    memset(dp, 0, sizeof dp);

    for (int c1 = Like ? M : min(M, MyW); c1 >= 0; --c1)
        for (int c2 = M - c1; c2 >= 0; --c2)
            for (int c3 = min(M - c1 - c2, DislikesW); c3 >= 0; --c3) {
                ll &res = dp[c1][c2][c3] = 0;
                const int myW = MyW + (Like ? c1 : -c1);
                const int likesW = LikesW + c2;
                const int dislikesW = DislikesW - c3;
                const int total = myW + likesW + dislikesW;

                if (c1 + c2 + c3 == M)
                    res = myW;
                else {
                    res += myW * mdInv[total] % mod * dp[c1 + 1][c2][c3];
                    res += likesW * mdInv[total] % mod * dp[c1][c2 + 1][c3];
                    res += dislikesW * mdInv[total] % mod * dp[c1][c2][c3 + 1];
                    res %= mod;
                }
            }

    return dp[0][0][0];
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    for (int i = 0; i < sizeof mdInv / sizeof mdInv[0]; ++i)
        mdInv[i] = modPow(i, mod - 2);

    int n, M;
    cin >> n >> M;
    vector<int> a(n), w(n);
    for (int &x : a)
        cin >> x;
    for (int &x : w)
        cin >> x;

    int likesW = 0, dislikesW = 0;
    for(int i = 0; i < n; ++i)
        (a[i] ? likesW : dislikesW) += w[i];

    for (int i = 0; i < n; ++i)
        cout << f(a[i], w[i], likesW - (a[i] ? w[i] : 0), dislikesW - (a[i] ? 0 : w[i]), M) << '\n';
    return 0;
}