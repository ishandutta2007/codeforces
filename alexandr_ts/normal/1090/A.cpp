#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

//const ll INF = 4e18 + 10;
//const ll MOD = 1e9 + 7;
//const ld EPS = 1e-9;
//const ld PI = acos(-1);
//const int M = 1e3 + 10;
//const int N = 1e6 + 10;
//
//ll a[N], b[N];
//
//void solve() {
//    ll n, l, r, x, y, z;
//    cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];
//    for (int i = 3; i <= n; i++) {
//        b[i] = (b[i - 2] * x + b[i - 1] * y + z) % (1ll << 32);
//    }
//    fr(i, n) {
//        a[i] = (b[i + 1]) % (r - l + 1) + l;
//        //cout << a[i] << " ";
//    }
//    //cout << endl;
//
//    ll ans = INF;
//    multiset<int> ms;
//    for (int i = n - 1; i >= 0; i--) {
//        auto it = ms.upper_bound(a[i]);
//        if (it != ms.end()) {
//            ans = min(ans, a[i] * (*it));
//        }
//        if (ms.size()) {
//            it = ms.end();
//            --it;
//            if (*it > a[i])
//                ans = min(ans, a[i] * (*it));
//        }
//        ms.insert(a[i]);
//    }
//    if (ans == INF)
//        cout << "IMPOSSIBLE\n";
//    else
//        cout << ans << "\n";
//}
//
//int main() {
//    //freopen("a.in", "r", stdin);
//    ios_base::sync_with_stdio(false);
//    int t;
//    cin >> t;
//    while (t--)
//        solve();
//}
const int N = 2e5;
const int M = 1e9;
ll cnt[N];
ll max_ind[N];
ll workers[N];
int main()
{
    ll n, m, mx_zp, mx_all = -1, mysum = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> m;
        cnt[i] = m;
        mx_zp = -1;
        for (ll j = 0; j < m; j++)
        {
            cin >> workers[j];
            if (workers[j] > mx_zp)
            {
                mx_zp = workers[j];
            }

        }
        max_ind[i] = mx_zp;
        if (mx_all < mx_zp)
        {
            mx_all = mx_zp;
        }
    }

    for (ll i = 0; i < n; i++)
    {
        mysum += cnt[i] * fabs(max_ind[i] - mx_all);
    }

    cout << mysum;
    return 0;
}