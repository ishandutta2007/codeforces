#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


vector<int> getPrimeDivs(int x) {
    assert(x > 0);
    vector<int> v;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            v.emplace_back(i);
            do x /= i;
            while (x % i == 0);
        }
    if (x != 1)
        v.emplace_back(x);

    return v;
}

const int MxN = (int) 1e6 + 9;
int n, A, B;
int a[MxN + 9];

ll f(const int d) {
    ll dp[2][3];
    memset(dp, 0, sizeof dp);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 2; j >= 0; --j) {
            ll &res = dp[i & 1][j] = 1LL << 60;
            if (j < 2)
                res = min(res, dp[i & 1][j + 1]);
            res = min(res, dp[~i & 1][j] +
                           (j == 1 ? A : a[i] % d == 0 ? 0 : min(a[i] % d, d - a[i] % d) == 1 ? B : 1LL << 60));
        }
    }
    return dp[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> A >> B;
    for(int i = 0; i < n; ++i)
        cin >>a[i];


    ll ans = 1LL << 60;

    for (int x : {a[0], a[n-1]})
        for (int y = max(2, x - 1); y <= x + 1; ++y)
            for (int z: getPrimeDivs(y))
                ans = min(ans, f(z));
    cout << ans;
    return 0;
}