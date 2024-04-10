#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &x:a)
        cin >> x;

    ll lo = 0, hi = 1e14;
    while(lo < hi) {
        const ll mid = (lo + hi) / 2;


        ll s = mid + a[0];
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] * 100 > k * s) {
                ok = false;
                break;
            }
            s += a[i];
        }
        if(ok)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--) {
     auto res = f();
     cout << res << '\n';
    }
    return 0;
}