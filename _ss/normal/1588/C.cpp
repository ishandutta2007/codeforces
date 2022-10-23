#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const int N = 3e5 + 10;
const ll inf = 1e18;
ll a[N], n;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        map<ll, vi> pos_odd, pos_even;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            a[i] -= a[i - 1];
            if (i & 1) pos_odd[a[i]].eb(i);
            else pos_even[a[i]].eb(i);
        }
        vector<pair<ll, ll>> odd, even;
        odd.eb(-inf, n + 1);
        even.eb(-inf, n + 1);
        if (n & 1) odd.eb(a[n], n);
        else even.eb(a[n], n);
        ll res = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int r1, r2;
            if (i & 1)
            {
                r1 = lower_bound(all(odd), mp(a[i], -inf)) - odd.begin();
                r1 = odd[r1 - 1].se - 1;
                r2 = lower_bound(all(even), mp(-a[i], -inf)) - even.begin();
                r2 = even[r2 - 1].se - 1;
                int r = min(r1, r2);
                res += upper_bound(all(pos_odd[a[i]]), r) - upper_bound(all(pos_odd[a[i]]), i);
                res += upper_bound(all(pos_even[-a[i]]), r) - upper_bound(all(pos_even[-a[i]]), i);
            }
            else
            {
                r1 = lower_bound(all(odd), mp(-a[i], -inf)) - odd.begin();
                r1 = odd[r1 - 1].se - 1;
                r2 = lower_bound(all(even), mp(a[i], -inf)) - even.begin();
                r2 = even[r2 - 1].se - 1;
                int r = min(r1, r2);
                res += upper_bound(all(pos_odd[-a[i]]), r) - upper_bound(all(pos_odd[-a[i]]), i);
                res += upper_bound(all(pos_even[a[i]]), r) - upper_bound(all(pos_even[a[i]]), i);
            }
            if (i & 1)
            {
                while (a[i] <= odd.back().fi) odd.pop_back();
                odd.eb(a[i], i);
            }
            else
            {
                while (a[i] <= even.back().fi) even.pop_back();
                even.eb(a[i], i);
            }
        }
        cout << res << "\n";
    }
    return 0;
}