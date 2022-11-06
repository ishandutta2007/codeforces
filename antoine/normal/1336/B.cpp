#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;


vector<int> a[3];

ll sq(ll x) {
    return x * x;
}

ll f(int x, int y, int z) {
    return sq(x - y) + sq(y - z) + sq(x - z);
}

void f() {
    {
        int n[3];
        for (int &x:n)
            cin >> x;
        for (int i = 0; i < 3; ++i) {
            a[i] = vector<int>(n[i]);
            for (int &x : a[i])
                cin >> x;
            sort(a[i].begin(), a[i].end());
        }
    }
    sort(a, a + 3);

    ll ans = (ll) 8e18;
    do {
        for (auto i = a[0].begin(), j = a[1].begin(), k = a[2].begin(); i != a[0].end(); ++i) {
            while (j != a[1].end() && *i > *j)
                ++j;
            if (j == a[1].end())
                break;
            while (k != a[2].end() && *j > *k)
                ++k;
            if (k == a[2].end())
                break;
            while (j + 1 != a[1].end() && f(*i, *(j + 1), *k) <= f(*i, *j, *k))
                ++j;
            ans = min(ans, f(*i, *j, *k));
            assert(*i <= *j && *j <= *k && 3);
        }
    } while (next_permutation(a, a + 3));
    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--)f();
    return 0;
}