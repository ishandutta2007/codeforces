#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define mp make_pair
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define pii pair<int, int>

const int maxn = (1 << 18);
int ma[2 * maxn];
int d[2 * maxn];
int n, m, p;
pii a[maxn];
pii b[maxn];
pair<pii, int> q[maxn];
int inf = 1e15;

void push(int i)
{
    d[i * 2] += d[i];
    ma[i * 2] += d[i];
    d[i * 2 + 1] += d[i];
    ma[i * 2 + 1] += d[i];
    d[i]= 0;
}

void add(int i, int l, int r, int left, int right, int x)
{
    if (right <= l || left >= r)
        return;
    if (left <= l && r <= right)
    {
        ma[i] += x;
        d[i] += x;
        return;
    }
    push(i);
    add(i * 2, l, (l + r) / 2, left, right, x);
    add(i * 2 + 1, (l + r) / 2, r, left, right, x);
    ma[i] = max(ma[i * 2], ma[i * 2 + 1]);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r",stdin);
        //freopen("output.txt", "w",stdout);
    #endif
    cin >> n >> m >> p;
    vector<pii> kek(n);
    for (int i = 0; i < n; i++)
        cin >> kek[i].ff >> kek[i].ss;
    sort(all(kek));
    int pt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1 || kek[i].ss < a[pt - 1].ss)
        {
            a[pt] = kek[i];
            pt++;
        }
    }
    n = pt;
    reverse(a, a + n);
    kek.resize(m);
    for (int i = 0; i < m; i++)
        cin >> kek[i].ff >> kek[i].ss;
    sort(all(kek));
    pt = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        if (i == m - 1 || kek[i].ss < b[pt - 1].ss)
        {
            b[pt] = kek[i];
            pt++;
        }
    }
    m = pt;
    reverse(b, b + m);
    pt = 0;
    for (int i = 0; i < p; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int j = lower_bound(a, a + n, mp(x + 1, 0ll)) - a;
        if (j == n)
            continue;
        int e = lower_bound(b, b + m, mp(y + 1, 0ll)) - b;
        if (e == m)
            continue;
        q[pt] = mp(mp(j, e), z);
        pt++;
    }
    sort(q, q + pt);
    for (int i = 0; i < m; i++)
        ma[maxn + i] = -b[i].ss;
    for (int i = m; i < maxn; i++)
        ma[maxn + i] = -inf;
    for (int i = maxn - 1; i >= 1; i--)
        ma[i] = max(ma[i * 2], ma[i * 2 + 1]);
    int j = 0;
    int ans = -inf;
    for (int i = 0; i < n; i++)
    {
        add(1, 0, maxn, 0, maxn, -(a[i].ss - (i ? a[i - 1].ss : 0)));
        while (j < pt && q[j].ff.ff == i)
        {
            add(1, 0, maxn, q[j].ff.ss, maxn, q[j].ss);
            j++;
        }
        ans = max(ans, ma[1]);
    }
//    for (int i = 0; i < m; i++)
//        cout << b[i].ff << " " << b[i].ss << "\n";
    cout << ans;
}