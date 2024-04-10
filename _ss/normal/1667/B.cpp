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

const int N = 5e5 + 10;
int n, m, bit1[N], bit2[N];
ll ps[N];

void add(int pos, int x, int bit[])
{
    for (int i = pos; i <= m; i += (i & -i)) bit[i] = max(bit[i], x);
}

int get(int pos, int bit[])
{
    int res = -1e9;
    for (int i = pos; i; i -= (i & -i)) res = max(res, bit[i]);
    return res;
}

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
        vll val;
        val.eb(0);
        for (int i = 1, x; i <= n; ++i) cin >> x, ps[i] = ps[i - 1] + x, val.eb(ps[i]);
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
        m = val.size();
        for (int i = 1; i <= m; ++i) bit1[i] = bit2[i] = -1e9;
        int pos = lower_bound(all(val), 0) - val.begin() + 1;
        add(pos, 0, bit1);
        add(m - pos + 1, 0, bit2);
        int res = 0;
        map<ll, int> best;
        best[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            pos = lower_bound(all(val), ps[i]) - val.begin() + 1;
            res = max(i + get(pos - 1, bit1), - i + get(m - pos, bit2));
            if (best.count(ps[i])) res = max(res, best[ps[i]]);
            if (!best.count(ps[i])) best[ps[i]] = res;
            else best[ps[i]] = max(best[ps[i]], res);
            add(pos, res - i, bit1);
            add(m - pos + 1, res + i, bit2);
        }
        cout << res << "\n";
    }
    return 0;
}