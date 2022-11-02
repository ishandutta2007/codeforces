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

const int MAXN = 7009;
pair<pii, int> a[MAXN];
int n;
int lg = 60;
int q[MAXN];
int pt = 0;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ff.ss;
        for (int e = 0; e < lg; e++)
        {
            if (a[i].ff.ss & (1ll << e))
                a[i].ff.ff++;
        }
    }
    for (int i = 0; i < n; i++)
        cin >> a[i].ss;
    sort(a, a + n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        //cout << "    " << a[i].ff.ss << "\n";
        if ((i > 0 && a[i].ff.ss == a[i - 1].ff.ss) || (i < n - 1 && a[i].ff.ss == a[i + 1].ff.ss))
        {
            ans += a[i].ss;
            if (pt == 0 || q[pt - 1] != a[i].ff.ss)
            {
                q[pt] = a[i].ff.ss;
                //cout << q[pt] << "\n";
                pt++;
            }
            continue;
        }
        bool u = false;
        for (int e = 0; e < pt; e++)
        {
            //cout << " " << q[e] << " " << a[i].ff.ss << "\n";
            if ((q[e] & a[i].ff.ss) == a[i].ff.ss)
            {
                u = true;
                break;
            }
        }
        //cout << u << " " << a[i].ss << "\n";
        if (u)
            ans += a[i].ss;
        if (u && (pt == 0 || q[pt - 1] != a[i].ff.ss))
        {
            q[pt] = a[i].ff.ss;
            pt++;
        }
    }
    cout << ans;
}