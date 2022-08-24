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

const int N = 500 + 1;

string s[N];
int dp[N][N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        int die = 0;
        vector <int> res(m + 1, 1e9);
        for (int l = 0; l < m; l++)
        {
            int cur = die;
            for (int r = m - 1; r >= l; r--)
            {
                res[cur] = min(res[cur], r - l + 1);
                cur += (s[i][r] == '1');
            }
            die += (s[i][l] == '1');
        }
        res[die] = 0;
        for (int j = 0; j <= k; j++)
        {
            for (int x = 0; x + j <= k && x <= m; x++)
            {
                dp[i + 1][j + x] = min(dp[i + 1][j + x], dp[i][j] + res[x]);
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);
    cout << ans << '\n';
}