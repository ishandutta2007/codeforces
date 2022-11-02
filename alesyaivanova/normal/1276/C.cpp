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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    vector<pii> cur;
    for (pii e : m)
        cur.pb(e.ss, e.ff);
    sort(all(cur));
//    for (pii e : cur)
//        cout << e.ff << " " << e.ss << "\n";
    int j = 0;
    pii opt(1, 1);
    int sum = 0;
    for (int len = 1; len * len <= n; len++)
    {
        while (j < (int)cur.size() && cur[j].ff < len)
        {
            sum += cur[j].ff;
            j++;
        }
        int kek = sum + ((int)cur.size() - j) * len;
//        cout << "   " << len << " " << kek << "\n";
        if (kek >= len * len)
        {
            kek = len * (kek / len);
            if (kek > opt.ff * opt.ss)
            {
                opt.ff = len;
                opt.ss = kek / len;
            }
        }
    }
    pii pos(0, 0);
    int cnt = 0;
    int ans[opt.ff][opt.ss] = {};
    int S = opt.ff * opt.ss;
    for (int i = (int)cur.size() - 1; i >= 0 && cnt < S; i--)
    {
        for (int e = 0; e < opt.ff && e < cur[i].ff && cnt < S; e++)
        {
//            cout << pos.ff << " " << pos.ss << "\n";
            ans[pos.ff][pos.ss] = cur[i].ss;
            pos.ff++; pos.ss++;
            if (pos.ff == opt.ff)
            {
                pos.ff = 0;
                pos.ss -= opt.ff - 1;
            }
            pos.ss = (pos.ss + 2 * opt.ss) % opt.ss;
            cnt++;
        }
    }
    cout << S << "\n";
    cout << opt.ff << " " << opt.ss << "\n";
    for (int i = 0; i < opt.ff; i++)
    {
        for (int e = 0; e < opt.ss; e++)
            cout << ans[i][e] << " ";
        cout << "\n";
    }
}