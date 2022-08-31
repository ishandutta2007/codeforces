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

const int N = 100 + 1;
const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= M) a -= M;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

int dp[N][N][N];
int go[N][2];
int cnt[N][N][N];
int link[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    for (int i = 0; i <= n; i++)
    {
        if (i != 0 && i != 1)
        {
            link[i] = go[link[i - 1]][s[i - 1] - '0'];
        }
        else
        {
            link[i] = 0;
        }
        for (int t = 0; t < 2; t++)
        {
            if (i != n && s[i] - '0' == t)
            {
                go[i][t] = i + 1;
            }
            else
            {
                go[i][t] = go[link[i]][t];
            }
        }
    }
    for (int me = 0; me <= x; me++)
    {
        if (me >= 2)
        {
            for (int v = 0; v <= n; v++)
            {
                for (int to = 0; to <= n; to++)
                {
                    cnt[me][v][to] = add(cnt[me - 1][v][to], cnt[me - 2][v][to]);
                    dp[me][v][to] = add(dp[me - 1][v][to], dp[me - 2][v][to]);
                    int s = 0;
                    int ct = 0;
                    for (int go = 0; go <= n; go++)
                    {
                        s = add(s, mul(cnt[me - 1][v][go], dp[me - 2][go][to]));
                        s = add(s, mul(dp[me - 1][v][go], cnt[me - 2][go][to]));
                        ct = add(ct, mul(cnt[me - 1][v][go], cnt[me - 2][go][to]));
                    }
                    dp[me][v][to] = add(dp[me][v][to], s);
                    cnt[me][v][to] = add(cnt[me][v][to], ct);
                }
            }
        }
        else
        {
            for (int v = 0; v <= n; v++)
            {
                if (go[v][me] == n)
                {
                    dp[me][v][go[v][me]] = 1;
                }
                cnt[me][v][go[v][me]] = 1;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= n; j++)
    {
        ans = add(ans, dp[x][0][j]);
    }
    cout << ans << '\n';
}