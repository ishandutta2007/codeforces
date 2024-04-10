#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;

const int MaxFact = (int) 3e5 + 9;

ll fact[MaxFact + 9];
ll factInv[MaxFact + 9];

ll modPow(ll n, ll k) {
    ll res = 1;
    for (n %= mod; k; k >>= 1) {
        if (k & 1)
            res = res * n % mod;
        n = n * n % mod;
    }
    return res;
}


ll modInv(const ll x) {
    return modPow(x, mod - 2);
}

ll C(const int n, const int k) {
    return fact[n] * factInv[k] % mod * factInv[n - k] % mod;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    fact[0] = factInv[0] = 1;
    for (int i = 1; i <= MaxFact; ++i) {
        fact[i] = fact[i - 1] * i % mod;
        factInv[i] = modInv(fact[i]);
    }

    int n;
    cin >> n;
    vector<int> a(2*n);
    for(int &x: a)
        cin >> x;
    sort(a.begin(), a.end());


    ll sum = 0;
    for(int i = 0; i < 2*n; ++i)
        sum += a[i] * (i < n ? -1 : 1);

    sum %= mod;

    sum *= C(2*n, n);
    cout << (sum%mod+mod)%mod;


    return 0;
}