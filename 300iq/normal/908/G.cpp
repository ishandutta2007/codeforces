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

const int N = 700 + 1;
const int M = 1e9 + 7;

inline int add(int a, int b)
{
    return (a + b >= M ? a + b - M : a + b < 0 ? a + b + M : a + b);
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

int dp[11][N][N][2];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    string s;
    cin >> s;
    int n = (int) s.size();
    for (int x = 0; x <= 10; x++)
    {
        dp[x][0][0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int a = 0; a <= i; a++)
            {
                for (int t = 0; t < 2; t++)
                {
                    for (int dig = 0; dig < 10; dig++)
                    {
                        if (!t && dig > s[i] - '0') continue;
                        int new_t = (t | (dig < s[i] - '0'));
                        int new_a = a + (dig < x);
                        dp[x][i + 1][new_a][new_t] = add(dp[x][i + 1][new_a][new_t], dp[x][i][a][t]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int x = 0; x <= 9; x++)
    {
        int cur = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int s = 0;
            for (int j = 0; j <= i; j++)
            {
                for (int t = 0; t < 2; t++)
                {
                    s = add(s, dp[x][n][j][t]); 
                    s = add(s, -dp[x + 1][n][j][t]);
                }
            }
            ans = add(ans, mul(s, mul(x, cur)));
            cur = mul(cur, 10);
        }
    }
    printf("%d\n", ans);
}