#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 1;
int dp[N][2];
vector <pair <int, int> > t;
int n;

bool check(int m)
{
    ll cur_rate = m;
    for (int i = 0; i < n; i++)
    {
        if (t[i].second == 2 && cur_rate >= 1900)
        {
            return 0;
        }
        if (t[i].second == 1 && cur_rate < 1900)
        {
            return 0;
        }
        cur_rate += t[i].first;
    }
    return 1;
}

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
    cin >> n;
    int sm = -1e9, sx = 1e9;
    for (int i = 0; i < n; i++)
    {
        int c, d;
        cin >> c >> d;
        t.push_back({c, d});
    }
    ll min_rate = -1e9, max_rate = 1e9;
    bool lim = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].second == 2)
        {
            max_rate = min(max_rate, 1899ll);
            lim = 1;
        }
        else
        {
            min_rate = max(min_rate, 1900ll);
        }
        if (min_rate > max_rate)
        {
            cout << "Impossible\n";
            return 0;
        }
        max_rate += t[i].first;
        min_rate += t[i].first;
    }
    if (lim)
    {
        cout << max_rate << '\n';
    }
    else
    {
        cout << "Infinity\n";
    }
}