
/*
    !  !!!
   
   
   
   
   
   
   
   
   
   
   
*/

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

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 64;

int p[N][N];
double dp[N][N];
double pr[N][N];
int cur = 1;

void dfs(int v, int l, int r, int cur)
{
    if (r - l == 1)
    {
        dp[v][2 * l] = p[2 * l][2 * l + 1] / 100.0;
        dp[v][2 * l + 1] = p[2 * l + 1][2 * l] / 100.0;
        pr[v][2 * l] = dp[v][2 * l];
        pr[v][2 * l + 1] = dp[v][2 * l + 1];
    }
    else
    {
        int m = (l + r) / 2;
        dfs(v * 2 + 1, l, m, cur / 2);
        dfs(v * 2 + 2, m, r, cur / 2);
        for (int i = l; i < m; i++)
        {
            for (int j = m; j < r; j++)
            {
                for (int a = 2 * i; a <= 2 * i + 1; a++)
                {
                    for (int b = 2 * j; b <= 2 * j + 1; b++)
                    {
                        /*
                        dp[v][a] = max(dp[v][a], dp[v * 2 + 1][a] + dp[v * 2 + 2][b] + pr[v * 2 + 1][a] * p[a][b] / 100.0 * cur);
                        //cout << dp[v * 2 + 1][a] << ' ' << dp[v * 2 + 2][b] << ' ' << pr[v * 2 + 1][a] * p[a][b] / 100.0 * cur << ' ' << dp[v][a] << endl;
                        dp[v][b] = max(dp[v][b], dp[v * 2 + 1][a] + dp[v * 2 + 2][b] + pr[v * 2 + 2][b] * p[b][a] / 100.0 * cur);
                        */
                        //cout << a << ' ' << b << ' ' << dp[v * 2 + 1][a] << ' ' << dp[v * 2 + 2][b] << ' ' << pr[v * 2 + 2][b] * p[b][a] / 100.0 * cur << ' ' << dp[v][b] << endl;
                        pr[v][a] += pr[v * 2 + 1][a] * pr[v * 2 + 2][b] * p[a][b] / 100.0;
                        pr[v][b] += pr[v * 2 + 1][a] * pr[v * 2 + 2][b] * p[b][a] / 100.0;
                        pr[v][a] = min(pr[v][a], 1.0);
                        pr[v][b] = min(pr[v][b], 1.0);
                    }
                }
            }
        }
        for (int i = l; i < m; i++)
        {
            for (int j = m; j < r; j++)
            {
                for (int a = 2 * i; a <= 2 * i + 1; a++)
                {
                    for (int b = 2 * j; b <= 2 * j + 1; b++)
                    {
                        dp[v][a] = max(dp[v][a], dp[v * 2 + 1][a] + dp[v * 2 + 2][b] + pr[v][a] * cur);
                        dp[v][b] = max(dp[v][b], dp[v * 2 + 1][a] + dp[v * 2 + 2][b] + pr[v][b] * cur);
                    }
                }
            }
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    int m = (1 << n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
    }
    dfs(0, 0, m / 2, m / 2);
    double ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, dp[0][i]);
    }
    cout << fixed << setprecision(20) << ans << endl;
}