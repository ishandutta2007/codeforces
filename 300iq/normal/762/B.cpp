#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int a, b, x;
    cin >> a >> b >> x;
    int m;
    cin >> m;
    vector <pair <int, string> > d;
    for (int i = 0; i < m; i++)
    {
        int val;
        string s;
        cin >> val >> s;
        d.push_back({val, s});
    }
    sort(d.begin(), d.end());
    ll ans = 0;
    int cnt = 0;
    for (auto c : d)
    {
        if (c.second == "USB")
        {
            if (a)
            {
                cnt++;
                a--;
                ans += c.first;
            }
            else
            {
                if (x)
                {
                    cnt++;
                    x--;
                    ans += c.first;
                }
            }
        }
        else
        {
            if (b)
            {
                cnt++;
                b--;
                ans += c.first;
            }
            else
            {
                if (x)
                {
                    cnt++;
                    x--;
                    ans += c.first;
                }
            }
        }
    }
    cout << cnt << ' ' << ans << '\n';
}