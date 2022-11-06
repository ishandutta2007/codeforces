#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m, k;
    ll ta, tb;

    cin >> n >> m >> ta >> tb >> k;
    vector<ll> a(n), b(m);
    for (ll &x : a)
        cin >> x;
    for (ll &x : b)
        cin >> x;


    if (k >= min(n, m)) {
        cout << -1;
        return 0;
    }


    ll ans = 0;
    for (int i = 0; i <= k; ++i) {
        assert(i < n);
        int j = lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
        j += k - i;
        if(j >= m) {
            cout << -1;
            return 0;
        }

        ans = max(ans, b[j] + tb);
    }
    cout << ans;
    return 0;
}