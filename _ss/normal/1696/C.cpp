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
using pll = pair<ll, ll>;

const int N = 1e5 + 10;

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pll> vt1;
        vt1.eb(0, 0);
        for (int i = 1, x; i <= n; ++i)
        {
            cin >> x;
            int sl = 1;
            while (x % m == 0) x /= m, sl *= m;
            if (vt1.back().fi == x) vt1.back().se += sl;
            else vt1.eb(x, sl);
        }
        cin >> n;
        vector<pll> vt2;
        vt2.eb(0, 0);
        for (int i = 1, x; i <= n; ++i)
        {
            cin >> x;
            int sl = 1;
            while (x % m == 0) x /= m, sl *= m;
            if (vt2.back().fi == x) vt2.back().se += sl;
            else vt2.eb(x, sl);
        }
        if (vt1 == vt2) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}