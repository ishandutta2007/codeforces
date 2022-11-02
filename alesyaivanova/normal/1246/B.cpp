#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 9;
int n, k;
int a[MAXN];
map<vector<pii>, int> m;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<pii> cur;
        for (int e = 2; e * e <= x; e++)
        {
            if (x % e != 0)
                continue;
            int cnt = 0;
            while (x % e == 0)
            {
                cnt++;
                x /= e;
            }
            if (cnt % k != 0)
                cur.pb(e, cnt % k);
        }
        if (x != 1)
            cur.pb(x, 1);
        vector<pii> rev(all(cur));
        for (int e = 0; e < (int)rev.size(); e++)
            rev[e].ss = k - rev[e].ss;
        auto j = m.find(rev);
        if (j != m.end())
            ans += (*j).ss;
        m[cur]++;
    }
    cout << ans;
}