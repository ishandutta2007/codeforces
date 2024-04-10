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

const int N = 2e5 + 10;

int a[N], n, m;

bool cmp(pii x, pii y)
{
    if (x.fi == y.fi) return x.se > y.se;
    return x.fi < y.fi;
}

bool check(int x, vector<pair<pii, pii>> &segment)
{
    int k = segment.size();
    vi ps(n + 2, 0);
    for (auto pa : segment)
    {
        int l1 = pa.fi.fi;
        int r1 = pa.fi.se;
        if (r1 - l1 + 1 > x)
        {
            l1 = 0;
            r1 = -1;
        }
        else
        {
            int tmp = l1;
            l1 = max(r1 - x + 1, 1);
            r1 = tmp;
        }

        int l2 = pa.se.fi;
        int r2 = pa.se.se;
        if (r2 - l2 + 1 > x)
        {
            l2 = 0;
            r2 = -1;
        }
        else
        {
            int tmp = l2;
            l2 = max(r2 - x + 1, 1);
            r2 = tmp;
        }
        if (r1 >= l2 && r1 != -1 && r2 != -1)
        {
            ps[l1]++;
            ps[r2 + 1]--;
        }
        else
        {
            ps[l1]++;
            ps[r1 + 1]--;
            ps[l2]++;
            ps[r2 + 1]--;
        }
    }
    int val = 0;
    for (int i = 1; i <= n; ++i)
    {
        val += ps[i];
        if (val == k) return true;
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<pii> vt2, vt;
    for (int i = 1, l, r; i <= m; ++i)
    {
        cin >> l >> r;
        vt2.eb(l, r);
    }
    sort(all(vt2), cmp);
    int mx = 0;
    for (pii pa : vt2)
        if (pa.se > mx) mx = pa.se, vt.eb(pa);
    map<int, set<int>> st;
    int l = 0, r = -1;
    vector<pair<pii, pii>> segment;
    for (pii pa : vt)
    {
        //cout << pa.fi << " " << pa.se << "\n";
        int l2 = pa.fi, r2 = pa.se;
        if (l2 <= r)
        {
            for (int i = l; i < l2; ++i) st[a[i]].erase(i);
            l = l2;
        }
        else
        {
            for (int i = l; i <= r; ++i) st[a[i]].erase(i);
            l = l2;
            r = l - 1;
        }
        set<int> change;
        for (int i = r + 1; i <= r2; ++i)
        {
            st[a[i]].insert(i);
            change.insert(a[i]);
        }
        r = r2;
        for (int id : change)
            if ((int)st[id].size() >= 2)
            {
                int b1 = *st[id].begin();
                int b2 = *next(st[id].begin());
                int e1 = *prev(st[id].end());
                int e2 = *prev(prev(st[id].end()));
                segment.eb(mp(b1, e2), mp(b2, e1));
                //cout << b1 << " " << e2 << " " << b2 << " " << e1 << "\n";
            }
    }
    l = 0, r = n;
    int ans = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid, segment)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("ss.inp", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}