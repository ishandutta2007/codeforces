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

using namespace std;

typedef unsigned long long ll;

mt19937 rnd_64(time(0));

const int N = 5032107 + 7;

int lp[N];
int press[N];

const int M = 194598 + 7;
const int LIM = 15;

int ans[LIM][M];

int dp[1 << 7];
int cnt[1 << 7];
int lf[1 << 7];
int go[1 << 7];

const int T = 3e7;

vector <pair <int, int> > res[T];
int st[8];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int mask = 0; mask < (1 << 7); mask++)
    {
        cnt[mask] = __builtin_popcount(mask);
        for (int i = 0; i < 7; i++)
        {
            if ((mask >> i) & 1)
            {
                lf[mask] = i;
                go[mask] = mask - (1 << i);
            }
        }
    }
    for (int i = 0; i < N; i++) press[i] = -1;
    for (int i = 2; i < N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            for (int j = i + i; j < N; j += i)
            {
                lp[j] = i;
            }
        }
    }
    int sz = 0;
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        int x = a[i];
        vector <int> ret;
        while (x != 1)
        {
            int cur = lp[x];
            int deg = 0;
            while (x % cur == 0)
            {
                x /= cur;
                deg++;
            }
            if (deg % 2)
            {
                ret.push_back(cur);
            }
        }
        int ct = (int) ret.size();
        int lim = (1 << ct);
        dp[0] = 1;
        for (int mask = 1; mask < lim; mask++)
        {
            dp[mask] = dp[go[mask]] * ret[lf[mask]];
        }
        for (int mask = 0; mask < lim; mask++)
        {
            if (press[dp[mask]] == -1)
            {
                press[dp[mask]] = sz++;
            }
            res[press[dp[mask]]].push_back({i, ct - cnt[mask]});
        }
    }
    for (int i = 0; i <= 14; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = n;
        }
    }
    for (int j = 0; j < sz; j++)
    {
        for (int x = 0; x <= 7; x++)
        {
            st[x] = n;
        }
        for (auto c : res[j])
        {
            for (int x = 0; x <= 7; x++)
            {
                if (st[x] != n)
                {
                    ans[x + c.second][st[x]] = min(ans[x + c.second][st[x]], c.first);
                }
            }
            st[c.second] = c.first;
        }
    }
    for (int i = 0; i <= 14; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            ans[i][j] = min(ans[i][j], ans[i][j + 1]);
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        for (int x = 0; x <= 14; x++)
        {
            if (ans[x][l] <= r)
            {
                cout << x << '\n';
                break;
            }
        }
    }
}