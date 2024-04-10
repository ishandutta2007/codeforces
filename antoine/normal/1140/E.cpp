#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;
const int MxN = (int) 2e5 + 9;
ll p2[MxN + 9];


ll f(vector<int> &v, const int k) {
    const int n = (int) v.size();

    ll res1 = 1, res2 = v[0] == -1, spe = max(1, v[0]);

    v.erase(v.begin());

    for (const int &x : v) {
        if (x == -1) {
            ll t = res2 * (k - 2LL) + res2;
            res2 = res2 * (k - 2LL) + res1;
            res1 = t;

        } else {
            res1 = res2 * (k - 2LL) + (spe == x ? res2 : res1);
            res2 = 0;
            spe = x;
        }
        res1 %= mod;
        res2 %= mod;
    }

    const ll res = (res1 + res2 * (k - 1LL)) % mod;
    return res;

    // all -1
    // -1 left
    // -1 right
    // -1 same
    // -1 diff
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    p2[0] = 1;
    for (int i = 1; i <= MxN; ++i)
        p2[i] = p2[i - 1] * 2 % mod;

    int n, k;
    cin >> n >> k;

    vector<int> v1, v2;

    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        (i & 1 ? v1 : v2).push_back(x);
    }

    cout << f(v1, k) * f(v2, k) % mod;

    return 0;
}