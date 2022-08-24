#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 21;
const int M = 2e5;

ll dp[N][N];
ll ndp[N][N];
int ind[N][M];
bool genius[M];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> x(n), y(n);
    vector <pair <int, int> > e;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        ans += y[i];
        e.push_back({-y[i] + x[i], i});
    }
    vector <int> best(n, n);
    for (int type = 0; type <= a; type++)
    {
        vector <pair <ll, int> > e;
        for (int i = 0; i < n; i++)
        {
            e.push_back({-y[i] + x[i] * (1ll << type), i});
        }
        int lim = n - min(a + 7, n);
        nth_element(e.begin(), e.begin() + lim, e.end());
        reverse(e.begin(), e.end());
        for (int i = 0; i < (int) e.size(); i++)
        {
            if (i <= a + 7)
            {
                ind[type][e[i].second] = a;
                genius[e[i].second] = true;
            }
        }
    }
    for (int type = 0; type <= a; type++)
    {
        vector <pair <ll, int> > e;
        for (int i = 0; i < n; i++)
        {
            e.push_back({x[i] * (1ll << type), i});
        }
        int lim = n - min(a + 7, n);
        nth_element(e.begin(), e.begin() + lim, e.end());
        reverse(e.begin(), e.end());
        for (int i = 0; i < (int) e.size(); i++)
        {
            if (i <= a + 7)
            {
                ind[type][e[i].second] = a;
                genius[e[i].second] = true;
            }
        }
    }
    sort(e.rbegin(), e.rend());
    for (int i = 0; i <= a; i++) for (int j = 0; j <= a; j++) dp[i][j] = -1e18;
    dp[0][0] = 0;
    for (int i = 0; i < (int) e.size() && i < b; i++)
    {
        for (int x = 0; x <= a; x++)
        {
            for (int y = 0; y <= a; y++)
            {
                ndp[x][y] = dp[x][y];
            }
        }
        ll val = max(0, e[i].first);
        for (int skip = 0; skip <= a; skip++)
        {
            for (int grab = 0; grab <= a; grab++)
            {
                ndp[skip][grab] = max(ndp[skip][grab], dp[skip][grab] + val);
                if (skip + 1 <= a) ndp[skip + 1][grab] = max(ndp[skip + 1][grab], dp[skip][grab]);
            }
        }
        if (genius[e[i].second])
        for (int skip = 0; skip <= a; skip++)
        {
            ll new_x = x[e[i].second];
            ll new_y = y[e[i].second];
            for (int grab = 1; grab <= a; grab++)
            {
                new_x *= 2;
                if (ind[grab][e[i].second] <= a)
                {
                    for (int have = 0; have + grab <= a; have++)
                    {
                        ndp[skip][have + grab] = max(ndp[skip][have + grab], dp[skip][have] + new_x - new_y);
                    }
                }
            }
        }
        for (int i = 0; i <= a; i++)
        {
            for (int j = 0; j <= a; j++)
            {
                dp[i][j] = ndp[i][j];
            }
        }
    }
    for (int i = b; i < (int) e.size(); i++)
    {
        for (int x = 0; x <= a; x++)
        {
            for (int y = 0; y <= a; y++)
            {
                ndp[x][y] = dp[x][y];
            }
        }
        if (genius[e[i].second])
        for (int skip = 0; skip <= a; skip++)
        {
            if (skip)
            {
                ll new_x = x[e[i].second];
                ll new_y = y[e[i].second];
                for (int grab = 1; grab <= a; grab++)
                {
                    new_x *= 2;
                    if (ind[grab][e[i].second] <= a)
                    {
                        for (int have = 0; have + grab <= a; have++)
                        {
                            ndp[skip - 1][have + grab] = max(ndp[skip - 1][have + grab], dp[skip][have] + new_x - new_y);
                        }
                    }
                }
            }
        }
        for (int x = 0; x <= a; x++)
        {
            for (int y = 0; y <= a; y++)
            {
                dp[x][y] = ndp[x][y];
            }
        }
    }
    ll as = 0;
    for (int x = 0; x <= a; x++)
    {
        for (int y = 0; y <= a; y++)
        {
            as = max(as, dp[x][y]);
        }
    }
    cout << ans + as << '\n';
}