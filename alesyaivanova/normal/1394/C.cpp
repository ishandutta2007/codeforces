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

const int maxn = 3e5 + 9;
pii a[maxn];
int n;

pair<bool, pii> check(int l, int r, int u, int d, int kek1, int kek2)
{
    if (r < l || u < d || kek1 < kek2 || kek2 > u - l || kek1 < d - r)
        return mp(0, mp(0, 0));
    if (kek1 > u - l)
        return mp(1, mp(l, u));
    if (kek1 >= u - r)
        return mp(1, mp(u - kek1, u));
    return mp(1, mp(r, r + kek1));
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int l, r, u, d, kek1, kek2;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int e = 0; e < (int)s.size(); e++)
        {
            if (s[e] == 'N')
                a[i].ff++;
            else
                a[i].ss++;
        }
        if (!i)
        {
            l = a[i].ff, r = a[i].ff;
            u = a[i].ss, d = a[i].ss;
            kek1 = a[i].ss - a[i].ff;
            kek2 = a[i].ss - a[i].ff;
        }
        else
        {
            l = min(l, a[i].ff);
            r = max(r, a[i].ff);
            u = max(u, a[i].ss);
            d = min(d, a[i].ss);
            kek1 = max(kek1, a[i].ss - a[i].ff);
            kek2 = min(kek2, a[i].ss - a[i].ff);
        }
    }
    int left = (max(r - l, max(u - d, kek1 - kek2)) + 1) / 2 - 1, right = 1e6;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        int l1 = r - 2 * mid, r1 = l;
        int d1 = u - 2 * mid, u1 = d;
        int kek11 = kek2 + mid, kek21 = kek1 - mid;
        if (check(l1, r1, u1, d1, kek11, kek21).ff)
            right = mid;
        else
            left = mid;
    }
    cout << right << "\n";
    int mid = right;
    int l1 = r - 2 * mid, r1 = l;
    int d1 = u - 2 * mid, u1 = d;
    int kek11 = kek2 + mid, kek21 = kek1 - mid;
    pii cur = (check(l1, r1, u1, d1, kek11, kek21)).ss;
    cur.ff += mid;
    cur.ss += mid;
    for (int i = 0; i < cur.ff; i++)
        cout << 'N';
    for (int i = 0; i < cur.ss; i++)
        cout << 'B';
}