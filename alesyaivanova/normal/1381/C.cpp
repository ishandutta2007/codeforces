#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

const int maxn = 1e5 + 9;
int a[maxn];
int b[maxn];
int cnt[maxn];
int n, x, y;
int num[maxn];

void solve()
{
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    y -= x;
    for (int i = 0; i <= n; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++)
        cnt[a[i]]++;
    set<pii> s;
    for (int i = 0; i <= n; i++)
        s.emplace(-cnt[i], i);
    for (int i = 0; i < x; i++)
    {
        pii cur = (*s.begin());
        s.erase(s.begin());
        cur.ff++;
        s.insert(cur);
    }
    int ma = -(*s.begin()).ff;
    int kek = n - x;
    if (ma > kek / 2)
    {
        kek = min(kek, (kek - ma) * 2);
        if (kek < y)
        {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i <= n; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++)
        b[i] = -1;
    vector<pii> p;
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
        if (cnt[a[i]] <= kek / 2 && (int)p.size() < kek)
            p.pb(a[i], i);
        else if (x)
        {
            b[i] = a[i];
            x--;
        }
    }
    sort(all(p));
    for (int i = 0; i < kek; i++)
    {
        int pos = p[i].ss;
        int col = p[(i + kek / 2) % kek].ff;
        if (y)
        {
            b[pos] = col;
            y--;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (!cnt[i])
        {
            for (int e = 0; e < n; e++)
            {
                if (b[e] == -1)
                    b[e] = i;
            }
            break;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << b[i] + 1 << " ";
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}