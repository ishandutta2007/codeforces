#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    const string s = "codeforces";
    const int n = (int)s.size();


    ll k;
    cin >> k;

    vector<ll> v(n, 1);
    for(;;) {
        ll p = accumulate(v.begin(), v.end(), 1LL, [](const ll x, const ll y) {
            return x*y;
        });
        if(p >= k)
            break;
        (*min_element(v.begin(), v.end()))++;
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < v[i]; ++j)
            cout << s[i];
    return 0;
}