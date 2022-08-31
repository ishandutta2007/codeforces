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
#include <chrono>

using namespace std;

typedef long long ll;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 6e5 + 7;

int cnt[N];
int ct[N];
int dp[N];
int pw[12];
int value[N];
int good[N];
int lf[N];
int buben[12][6];
int super_man[N];
int ret[2][6];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int w, n, m;
    cin >> w >> n >> m;
    pw[0] = 1;
    for (int i = 1; i < w; i++)
    {
        pw[i] = pw[i - 1] * 3;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ct[x]++;
        int val = 0;
        for (int j = 0; j < w; j++)
        {
            if ((x >> j) & 1) val += pw[j];
        }
        cnt[val]++;
    }
    int _ret = 1;
    for (int i = 0; i < w; i++) _ret *= 3;
    for (int i = 0; i < _ret; i++)
    {
        dp[i] = cnt[i];
        for (int j = 0; j < w; j++)
        {
            if ((i / pw[j]) % 3 == 2)
            {
                dp[i] = dp[i - pw[j]] + dp[i - 2 * pw[j]];
                break;
            }
        }
    }
    ret[0][0] = 2;
    ret[0][1] = 0;
    ret[0][2] = 0;
    ret[1][0] = 0;
    ret[1][1] = -1;
    ret[1][2] = 1;
    for (int a = 0; a < 2; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            if (ret[a][b] == 0)
            {
                ret[a][3 + b] = 1;
            }
            else if (ret[a][b] == 1)
            {
                ret[a][3 + b] = 0;
            }
            else if (ret[a][b] == 2)
            {
                ret[a][3 + b] = -1;
            }
            else
            {
                ret[a][3 + b] = 2;
            }
        }
    }
    int lim = (1 << w);
    for (int mask = 0; mask < lim; mask++)
    {
        for (int i = 0; i < w; i++)
        {
            if ((mask >> i) & 1)
            {
                lf[mask] = i;
            }
        }
    }
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            buben[i][j] = pw[i] * (ret[1][j] - ret[0][j]);
        }
    }
    for (int j = 0; j < 6; j++)
    {
        super_man[j] = (ret[1][j] == -1) - (ret[0][j] == -1);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        for (auto &c : s)
        {
            if (c == 'A') c = 0;
            else if (c == 'O') c = 1;
            else if (c == 'X') c = 2;
            else if (c == 'a') c = 3;
            else if (c == 'o') c = 4;
            else c = 5;
        }
        int ans = 0;
        for (int mask = 0; mask < lim; mask++)
        {
            value[mask] = 0;
            good[mask] = 0;
            if (mask == 0)
            {
                for (int i = 0; i < w; i++)
                {
                    good[mask] += (ret[0][s[i]] == -1);
                    value[mask] += pw[i] * ret[0][s[i]];
                }
            }
            else
            {
                int i = lf[mask];
                good[mask] = good[mask ^ (1 << i)] + super_man[s[i]];
                value[mask] = value[mask ^ (1 << i)] + buben[i][s[i]];
            }
            if (!good[mask])
            {
                ans += ct[mask] * dp[value[mask]];
            }
        }
        cout << ans << '\n';
    }
}