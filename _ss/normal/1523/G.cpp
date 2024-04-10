#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(vr) vr.begin(), vr.end()
#define vi vector<int>
#define vll vector<ll>
const int N = 1e5 + 10, inf = 1e9;

struct bit_2d
{
    vi bit[N], val[N];
    int n;

    void add_point(int x, int y)
    {
        for (int i = x; i <= n; i += (i & -i)) val[i].eb(y);
    }

    void build()
    {
        for (int i = 1; i <= n; ++i)
        {
            sort(all(val[i]));
            val[i].resize(unique(all(val[i])) - val[i].begin());
            bit[i].resize(val[i].size() + 1, inf);
        }
    }

    int find_pos(int y, vi &vt) { return upper_bound(all(vt), y) - vt.begin();}

    void update(int x, int y, int d)
    {
        for (int i = x; i <= n ; i += (i & -i))
            for (int j = find_pos(y, val[i]); j <= (int)val[i].size(); j += (j & -j)) bit[i][j] = min(bit[i][j], d);
    }

    int get(int x, int y)
    {
        int res = inf;
        for (int i = x; i; i -= (i & -i))
            for (int j = find_pos(y, val[i]); j; j -= (j & -j)) res = min(res, bit[i][j]);
        return res;
    }
} BIT;

int n, m;
pii a[N];
vi I[N];

int get_ans(int l, int r, int x)
{
    if (r - l + 1 < x) return 0;
    int id = BIT.get(n - l + 1, r);
    if (id == inf) return 0;
    return a[id].se - a[id].fi + 1 + get_ans(l, a[id].fi - 1, x) + get_ans(a[id].se + 1, r, x);
}

int ans[N];

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    BIT.n = n;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i].fi >> a[i].se;
        I[a[i].se - a[i].fi + 1].eb(i);
        BIT.add_point(n - a[i].fi + 1, a[i].se);
    }
    BIT.build();
    for (int i = n; i; --i)
    {
        for (int id : I[i]) BIT.update(n - a[id].fi + 1, a[id].se, id);
        ans[i] = get_ans(1, n, i);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << "\n";
    return 0;
}