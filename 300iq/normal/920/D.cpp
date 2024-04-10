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
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 5000 + 7;

int dp[N][N];
int cnt[N][N];
bitset <N> grab[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, v;
    cin >> n >> k >> v;
    vector <ll> a(n);
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if (v % k == 0)
    {
        if (s < v)
        {
            cout << "NO\n";
            return 0;
        }
        if (s >= v)
        {
            cout << "YES\n";
            for (int i = 1; i < n; i++)
            {
                if (a[i] != 0)
                {
                    int cnt = a[i] / k + bool(a[i] % k);
                    cout << cnt << ' ' << i + 1 << ' ' << 1 << '\n';
                }
            }
            if (v / k != 0)
            {
                cout << v / k << ' ' << 1 << ' ' << 2 << '\n';
            }
            return 0;
        }
    }
    vector <ll> ct(n);
    ll ss = 0;
    for (int i = 0; i < n; i++)
    {
        ct[i] += (a[i] / k);
        ss += a[i] / k * k;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = -1e9;
            cnt[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    cnt[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (dp[i + 1][j] < dp[i][j] || (dp[i + 1][j] == dp[i][j] && cnt[i + 1][j] < cnt[i][j]))
            {
                cnt[i + 1][j] = cnt[i][j];
                dp[i + 1][j] = dp[i][j];
                grab[i + 1][j] = 0;
            }
            if (dp[i + 1][(j + a[i]) % k] < dp[i][j] + a[i] % k || 
            (dp[i + 1][(j + a[i]) % k] == dp[i][j] && cnt[i + 1][(j + a[i]) % k] < cnt[i][j] + 1))
            {
                cnt[i + 1][(j + a[i]) % k] = cnt[i][j] + 1;
                dp[i + 1][(j + a[i]) % k] = dp[i][j] + a[i] % k;
                grab[i + 1][(j + a[i]) % k] = 1;
            }
        }
    }
    int cur = v % k;
    if (cnt[n][cur] <= 0)
    {
        cout << "NO\n";
        return 0;
    }
    int i = n;
    int who = -1;
    int trash = -1;
    vector <bool> ok(n);
    while (i)
    {
        if (grab[i][cur])
        {
            ok[i - 1] = true;
            who = i - 1;
            if (a[i - 1] % k != 0)
            {
                ct[i - 1]++;
            }
            cur = (cur - a[i - 1] % k + k) % k;
        }
        else
        {
            trash = i - 1;
        }
        i--;
    }
    vector <pair <int, pair <int, int> > >  e;
    if (trash != -1)
    {
        int was_ss = ss;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            if (!ok[i] && a[i] && i != trash)
            {
                ss -= a[i] / k * k;
                e.push_back({a[i] / k + bool(a[i] % k), {i + 1, trash + 1}});
                ct[i] = 0;
            }
            if (i == trash)
            {
                ct[i] = 0;
                ss -= a[i] / k * k;
            }
            if (!ok[i]) s += a[i], ct[i] = 0;
        }
        if (s / k)
        {
            ss += s / k * k;
            e.push_back({s / k, {trash + 1, who + 1}});
            a[who] += s / k * k;
        }
    }
    cur = v % k;
    if (ss + dp[n][cur] < v)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (auto c : e)
    {
        cout << c.first << ' ' << c.second.first << ' ' << c.second.second << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        if (i != who && ct[i] != 0)
        {
            cout << ct[i] << ' ' << i + 1 << ' ' << who + 1 << '\n';
            a[who] += a[i] / k * k;
            ct[i] -= a[i] / k;
            if (ct[i])
            {
                a[who] += a[i] % k;
            }
        }
    }
    assert(a[who] >= v && (a[who] - v) % k == 0);
    s = (a[who] - v) / k;
    if (s != 0)
    {
        if (who != 0)
        {
            cout << s << ' ' << who + 1 << ' ' << 1 << '\n';
        }
        else
        {
            cout << s << ' ' << who + 1 << ' ' << 2 << '\n';
        }
    }
}