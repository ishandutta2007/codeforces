#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
    ll d, m;
    cin >> d >> m;


    vector<ll> dp(99, 0);
    for(int i = 40; i >= 0; --i) {
        const ll mask = 1LL << i;
        ll &res = dp[i];
        if(mask > d) {
            res = 1;
            continue;
        }
        const ll cnt = (mask << 1) > d ? d - mask + 1 : mask;
        res = (cnt + 1) % m * dp[i+1] % m;
    }

    return ((dp[0] - 1)%m+m)%m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)cout << f() << '\n';

    return 0;
}